#include "Dcf77.h"

#include "Pins.h"
#include "RealTimeClock.h"
#include "InterruptsLock.h"

namespace
{
    constexpr struct
    {
        const unsigned long FILTER_TIME_MS = 20;
        const unsigned long SIGNAL_LOGIC_ONE_THRESHOLD_MS = 160;
        const unsigned long SIGNAL_END_OF_MESSAGE_THRESHOLD_MS = 1500;
        const unsigned long SIGNAL_OFF_MIN_TIME = 700;
        const unsigned long SIGNAL_OFF_MAX_TIME = 1950;
        const unsigned long SIGNAL_ON_MIN_TIME = 50;
        const unsigned long SIGNAL_ON_MAX_TIME = 300;
    } DCFSettings;

    void dcf77Interrupt()
    {
        // Only 'submit' signals once you know the period is really over.
        // This is only the case once we have seen a new signal of the opposite
        // value for a sufficient time.
        // E.g. once we observed '1' for >50ms, we know that the '0' is over
        // and can submit the '0'- duration.
        // We only see that we observed '1' long enough on the change to '0' again,
        // which makes this function very confusing.
        // About time measurement: usually a change starts with an unstable period,
        // followed by a stable period. To get the best temporal resolution,
        // the change should be measured at the start of the unstable period.
        unsigned long eventTime = millis();

        // Those are the signal values described earlier. If we see '1',
        // and the preceding '0' was long enough, we can submit the previous '1'.
        bool currentPinState = !digitalRead(PINS.DCF77); // Invert, as our DCF receiver delivers inverted signal
        bool signalObservedState = !currentPinState;
        bool signalPotentiallySubmittableState = currentPinState;

        // Write to HV_ENABLE, for debug purposes
        digitalWrite(PINS.HV_ENABLE, currentPinState);

        // Measure noisy signal duration
        static unsigned long lastSignalChangeTime = 0;
        unsigned long observedSignalDuration = eventTime - lastSignalChangeTime;
        lastSignalChangeTime = eventTime;

        // Ignore if the last signal change was too short
        if (observedSignalDuration < DCFSettings.FILTER_TIME_MS)
        {
            return;
        }

        // Keep track of when the previous signal ends and starts
        static unsigned long startOfPreviousSignalTime = 0;
        static unsigned long endOfPreviousSignalTime = 0;

        // Check if the signal changed, if not, that's all we had to do.
        static bool currentSignalState = true;
        if (currentSignalState == signalObservedState)
        {
            endOfPreviousSignalTime = eventTime;
            return;
        }
        currentSignalState = signalObservedState;

        // Now, we caught real signal state change.
        unsigned long submittableSignalDuration = endOfPreviousSignalTime - startOfPreviousSignalTime;
        unsigned long submittableSignalStartTime = startOfPreviousSignalTime;

        startOfPreviousSignalTime = endOfPreviousSignalTime;
        endOfPreviousSignalTime = eventTime;

        /*Serial.println();
        Serial.print("currentPinState: ");
        Serial.println(currentPinState);
        Serial.print("signalObservedState: ");
        Serial.println(signalObservedState);
        Serial.print("signalPotentiallySubmittableState: ");
        Serial.println(signalPotentiallySubmittableState);
        Serial.print("observedSignalDuration: ");
        Serial.println(observedSignalDuration);
        Serial.print("submittableSignalDuration: ");
        Serial.println(submittableSignalDuration);*/

        Dcf77.submitSignal(signalPotentiallySubmittableState, submittableSignalStartTime, submittableSignalDuration);
    }

} // namespace

void Dcf77_t::init()
{
    attachInterrupt(digitalPinToInterrupt(PINS.DCF77), dcf77Interrupt, CHANGE);
}

void Dcf77_t::updateData(const DcfTimeData &data, bool stable)
{
    if (debugMessageVerbosity >= 1)
    {
        if (stable)
        {
            Serial.println("New time data! (Stable)");
        }
        else
        {
            Serial.println("New time data! (Unstable)");
        }
    }
    InterruptsLock lock();
    currentData = data;
    currentDataStable = stable;
    newDataAvailable = true;
}

void Dcf77_t::handleNewTimeData(const DcfTimeData &data)
{
    if (debugMessageVerbosity >= 2)
    {
        Serial.print("  ");
        data.print();
    }

    if (data.rtcTimeValid)
    {
        long rtcOffset = static_cast<long>(data.unixTime - data.rtcTime);
        if (rtcOffset <= 2 && rtcOffset >= -2)
        {
            if (debugMessageVerbosity >= 1)
            {
                Serial.println("Stable: Change minimal.");
            }
            updateData(data, true);
            return;
        }

        if (currentData.valid)
        {
            long previousRtcOffset = static_cast<long>(currentData.unixTime - currentData.rtcTime);
            long offsetDifference = rtcOffset - previousRtcOffset;

            if (offsetDifference <= 2 && offsetDifference >= -2)
            {
                if (debugMessageVerbosity >= 1)
                {
                    Serial.println("Stable: Rtc offsets match.");
                }
                updateData(data, true);
                return;
            }
        }
    }

    if (currentData.valid)
    {
        long systemOffset = static_cast<long>(data.unixTime - data.systemTime / 1000);
        long previousSystemOffset = static_cast<long>(currentData.unixTime - currentData.systemTime / 1000);
        long offsetDifference = systemOffset - previousSystemOffset;

        if (offsetDifference <= 2 && offsetDifference >= -2)
        {
            if (debugMessageVerbosity >= 1)
            {
                Serial.println("Stable: System clock offsets match.");
            }
            updateData(data, true);
            return;
        }
    }

    updateData(data, false);
}

bool Dcf77_t::retrieveNewData(DcfTimeData &data, bool &stable)
{
    InterruptsLock lock();
    if (!newDataAvailable)
    {
        return false;
    }
    newDataAvailable = false;

    if (currentData.valid == false)
    {
        return false;
    }

    data = currentData;
    stable = currentDataStable;
    return true;
}

void Dcf77_t::submitSignal(bool positive, unsigned long startTime, unsigned long duration)
{
    static DcfTimeData data;
    static int writePosition = 0;
    static bool foundError = false;

    // Debug infos
    if (debugMessageVerbosity >= 5)
    {
        unsigned long lag = millis() - startTime;
        if (positive)
        {
            Serial.print("+        ");
        }
        else
        {
            Serial.print("-  ");
        }

        Serial.print(duration);
        Serial.print("    (lag: ");
        Serial.print(lag);
        Serial.print(" ms)");
        Serial.println();
    }

    // Sanity checks
    if ((positive && (duration > DCFSettings.SIGNAL_ON_MAX_TIME || duration < DCFSettings.SIGNAL_ON_MIN_TIME)) ||
        (!positive && (duration > DCFSettings.SIGNAL_OFF_MAX_TIME || duration < DCFSettings.SIGNAL_OFF_MIN_TIME)))
    {
        if (debugMessageVerbosity >= 1)
        {
            Serial.println("Invalid signal!");
        }
        data.valid = false;
        return;
    }

    // All non-positive handlers. Are a lot less, therefore extracted into this if.
    if (!positive)
    {
        // If we catch end-of-message signal
        if (duration > DCFSettings.SIGNAL_END_OF_MESSAGE_THRESHOLD_MS)
        {
            if (data.valid)
            {
                // Sync point is at the end of the long pause
                // we are currently in
                data.systemTime = startTime + duration;

                // This code will get run at ~100 ms into the new minute, so
                // this is a good point to read the rtc for comparison
                data.rtcTimeValid = RealTimeClock.isTimeValid();
                data.rtcTime = RealTimeClock.getTime().toUnixTime();

                // Submit timestamp
                handleNewTimeData(data);
            }
            else
            {
                if (debugMessageVerbosity >= 2)
                {
                    Serial.println();
                }
            }

            // Reset buffers.
            // Set data valid to true, as this is a valid start of data.
            // valid will be set to false as soon as any error occurs.
            writePosition = 0;
            data = DcfTimeData();
            data.valid = true;
            return;
        }

        // If we are in the long pause before end of message,
        // do the conversion to system time
        if (writePosition == 58 && data.valid)
        {
            data.unixTime = data.timestamp.toUnixTime();
        }
        return;
    }

    // Actual data bit
    bool value = duration > DCFSettings.SIGNAL_LOGIC_ONE_THRESHOLD_MS;

    // Print data to console if requested
    if (debugMessageVerbosity >= 2)
    {
        if (value)
        {
            Serial.print("1");
        }
        else
        {
            Serial.print("0");
        }

        if (writePosition % 5 == 4)
        {
            Serial.print(" ");
        }
    }

    if (value)
    {
        // If value is true, add respective value to the data
        switch (writePosition)
        {
        case 0:
            data.valid = false;
            break;
        case 17:
            data.timestamp.timezone += 2;
            break;
        case 18:
            data.timestamp.timezone += 1;
            break;
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
            data.timestamp.minutesByte() |= (1 << (writePosition - 21));
            break;
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
            data.timestamp.hoursByte() |= (1 << (writePosition - 29));
            break;
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
            data.timestamp.dayByte() |= (1 << (writePosition - 36));
            break;
        case 42:
        case 43:
        case 44:
            data.timestamp.dayOfWeekByte() |= (1 << (writePosition - 42));
            break;
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            data.timestamp.monthByte() |= (1 << (writePosition - 45));
            break;
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
            data.timestamp.yearByte() |= (1 << (writePosition - 50));
            break;

        default:
            break;
        }
    }

    // Parity checks
    static bool parity = false;
    if (writePosition == 20)
    {
        parity = 0;
    }
    else if (writePosition > 20)
    {
        parity ^= value;
        if (writePosition == 28 ||
            writePosition == 35 ||
            writePosition == 58)
        {
            if (parity)
            {
                if (debugMessageVerbosity >= 1)
                {
                    Serial.println("Parity error!");
                }
                data.valid = false;
            }
        }
    }

    // 'False' is only relevant for bit 20, therefore check
    // that explicitely and then continue
    if (writePosition == 20 && !value)
    {
        data.valid = false;
    }

    writePosition++;
}

Dcf77_t Dcf77;

void DcfTimeData::print() const
{
    Serial.print(valid ? "valid" : "invalid");
    Serial.print(" - Timezone:");
    Serial.print(timestamp.timezone);
    Serial.print(" - OffsetSystem:");
    Serial.print(unixTime - systemTime / 1000);
    Serial.print(" - OffsetRtc:");
    Serial.print(static_cast<long>(unixTime - rtcTime));
    Serial.print(" - RtcTime:");
    Serial.print(rtcTime);
    Serial.print(" - UnixTime:");
    Serial.print(unixTime);
    Serial.print(" - ");
    timestamp.print();
}
