#include "Dcf77.h"

#include "Pins.h"

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

    void dcf77Interrupt_proxy()
    {
        // Only 'submit' signals once you know the period is really over.
        // This is only the case once we have seen a new signal of the opposite
        // value for a sufficient time.
        // E.g. once we observed '1' for >50ms, we know that the '0' is over
        // and can submit the '0'- duration.
        // We only see that we observed '1' long enough on the change to '0' again,
        // which makes this function very confusing.
        static unsigned long lastRealSignalChangeTime = 0;
        static bool realSignalState = true;
        static unsigned long lastSignalChangeTime = 0;

        unsigned long eventTime = millis();

        // Those are the signal values described earlier. If we see '1',
        // and the preceding '0' was long enough, we can submit the previous '1'.
        bool currentPinState = !digitalRead(PINS.DCF77); // Invert, as our DCF receiver delivers inverted signal
        bool signalObservedState = !currentPinState;
        bool signalPotentiallySubmittableState = currentPinState;

        // Write to HV_ENABLE, for debug purposes
        digitalWrite(PINS.HV_ENABLE, currentPinState);

        unsigned long observedSignalDuration = eventTime - lastSignalChangeTime;
        unsigned long potentialSubmittableSignalEndTime = lastSignalChangeTime;
        lastSignalChangeTime = eventTime;

        // Ignore if the last signal change was too short
        if (observedSignalDuration < DCFSettings.FILTER_TIME_MS)
            return;

        // Ignore if the signal state we found was already the one currently active
        if (realSignalState == signalObservedState)
            return;

        // Now, we caught real signal state change.
        unsigned long submittableSignalDuration = potentialSubmittableSignalEndTime - lastRealSignalChangeTime;
        unsigned long submittableSignalStartTime = lastRealSignalChangeTime;
        lastRealSignalChangeTime = potentialSubmittableSignalEndTime;
        realSignalState = signalObservedState;

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
    attachInterrupt(digitalPinToInterrupt(PINS.DCF77), dcf77Interrupt_proxy, CHANGE);
}

void Dcf77_t::submitSignal(bool positive, unsigned long startTime, unsigned long duration)
{
    static int signalCounter = 0;

    unsigned long lag = millis() - startTime;
    /*if (positive)
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
    Serial.println();*/

    // Sanity checks
    if ((positive && (duration > DCFSettings.SIGNAL_ON_MAX_TIME || duration < DCFSettings.SIGNAL_ON_MIN_TIME)) ||
        (!positive && (duration > DCFSettings.SIGNAL_OFF_MAX_TIME || duration < DCFSettings.SIGNAL_OFF_MIN_TIME)))
    {
        Serial.println("Invalid!");
        signalCounter = 0;
        // TODO error handling
        return;
    }

    // Catch potential end-of-message signal
    if (!positive)
    {
        if (duration > DCFSettings.SIGNAL_END_OF_MESSAGE_THRESHOLD_MS)
        {
            signalCounter = 0;
            Serial.println();
        }
        return;
    }

    // Actual data bit
    bool value = duration > DCFSettings.SIGNAL_LOGIC_ONE_THRESHOLD_MS;

    if (value)
    {
        Serial.print("1");
    }
    else
    {
        Serial.print("0");
    }

    if (signalCounter % 5 == 4)
    {
        Serial.print(" ");
    }

    signalCounter++;
}

Dcf77_t Dcf77;