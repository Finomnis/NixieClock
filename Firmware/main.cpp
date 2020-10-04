#include <Arduino.h>

#include "RealTimeClock.h"
#include "Dcf77.h"
#include "Pins.h"
#include "NixieDisplay.h"
#include "SineAnimation.h"
#include "Settings.h"
#include "DimAnimation.h"

void setup()
{
    Serial.begin(115200);
    PINS.initializePins();
    NixieDisplay.init();
    RealTimeClock.init();
    Dcf77.init();
}

void updateDcf()
{
    // If dcf has new time available, synchronize RealTimeClock
    DcfTimeData dcfTimeData;
    bool dcfStable;
    if (Dcf77.retrieveNewData(dcfTimeData, dcfStable))
    {
        if (!dcfStable)
            return;

        uint8_t secondsOffset = 0;
        unsigned long syncTime = dcfTimeData.systemTime;
        while (syncTime < millis() + 500 && secondsOffset < 5)
        {
            syncTime += 1000;
            secondsOffset += 1;
        }

        if (secondsOffset >= 5)
        {
            Serial.println("Warning: Can't sync, delay was too big!");
            return;
        }

        // Adjust time
        RealTimeTimestamp t = dcfTimeData.timestamp;
        t.secondsByte() = secondsOffset;

        // Update display
        NixieDisplay.setColon(true);
        NixieDisplay.clearDots();
        NixieDisplay.setNumbers(t.getHoursMsd(),
                                t.getHoursLsd(),
                                t.getMinutesMsd(),
                                t.getMinutesLsd());
        NixieDisplay.flush();

        // Do a quick blink during waiting time, to show sync happened.
        if (Settings.COLON_BLINK_ON_SYNC)
        {
            // 200ms blink, starting at 400ms, ending at 600ms
            while (millis() + 600 < syncTime)
            {
            }

            // Set colon off
            NixieDisplay.setColon(false);
            NixieDisplay.flush();

            // End of 200ms blink
            while (millis() + 400 < syncTime)
            {
            }

            // Set colon on
            NixieDisplay.setColon(true);
            NixieDisplay.flush();
        }

        // Idle wait to sync point
        while (millis() < syncTime)
        {
        }

        // Sync
        RealTimeClock.setTime(t);
        //Serial.println("Synced!");
    }
}

void renderLoadingBar()
{
    unsigned long lastSync = Dcf77.getLastSyncTime();
    unsigned long now = millis();

    // Do a 'blink' on new time data
    if (now < lastSync + 200)
    {
        NixieDisplay.setDots(0xFF);
        SineAnimation.setActive(false);
        return;
    }
    if (now < lastSync + 500)
    {
        NixieDisplay.setDots(0x00);
        SineAnimation.setActive(false);
        return;
    }
    if (now < lastSync + 800)
    {
        NixieDisplay.setDots(0xFF);
        SineAnimation.setActive(false);
        return;
    }
    if (now < lastSync + 1100)
    {
        NixieDisplay.setDots(0x00);
        SineAnimation.setActive(false);
        return;
    }

    unsigned int receiveProgress = Dcf77.getReceiveProgress();
    unsigned int numProgressLeds = (receiveProgress * 7) / 58 + 1;

    if (receiveProgress == 0)
    {
        // If freshly initialized or not synced for a while, show resync bar
        SineAnimation.setActive(true);
        SineAnimation.update();
        return;
    }

    SineAnimation.setActive(false);
    NixieDisplay.clearDots();
    for (unsigned int i = 0; i < numProgressLeds; i++)
    {
        NixieDisplay.setDot(i);
    }
}

void updateDisplay()
{
    const auto &currentTime = RealTimeClock.getTime();

    // Numbers
    if (RealTimeClock.isTimeValid() && currentTime.isInitialized())
    {
        NixieDisplay.setNumbers(currentTime.getHoursMsd(),
                                currentTime.getHoursLsd(),
                                currentTime.getMinutesMsd(),
                                currentTime.getMinutesLsd());
    }
    else
    {
        NixieDisplay.setNumbers(-1, -1, -1, -1);
    }

    // Colon
    if (RealTimeClock.isTimeValid() && currentTime.isInitialized() &&
        (Dcf77.getLastStableSyncTime() + Settings.TIME_UNTIL_DCF_ANIMATION_SHOWS_AGAIN) > millis())
    {
        if (Settings.COLON_BLINK_EVERY_SECOND)
        {
            NixieDisplay.setColon(currentTime.getSecondsLsd() % 2 == 0);
        }
        else
        {
            NixieDisplay.setColon(true);
        }
    }
    else
    {
        NixieDisplay.setColon(!digitalRead(PINS.DCF77));
    }

    // Dots
    if (RealTimeClock.isTimeValid() && currentTime.isInitialized() &&
        (Dcf77.getLastStableSyncTime() + Settings.TIME_UNTIL_DCF_ANIMATION_SHOWS_AGAIN) > millis())
    {
        NixieDisplay.clearDots();
    }
    else
    {
        renderLoadingBar();
    }

    if (Settings.DISPLAY_DIM_AT_NIGHT)
    {
        static bool currentlyDimmed = false;

        uint16_t dayMinutes = currentTime.getMinutes() + 60L * currentTime.getHours();
        bool shouldBeDimmed = (Settings.DISPLAY_DIM_START < Settings.DISPLAY_DIM_END)
                                  ? (dayMinutes >= Settings.DISPLAY_DIM_START && dayMinutes < Settings.DISPLAY_DIM_END)
                                  : (dayMinutes >= Settings.DISPLAY_DIM_START || dayMinutes < Settings.DISPLAY_DIM_END);

        if (shouldBeDimmed != currentlyDimmed)
        {
            // Don't do anything for the first 5 seconds of the minute, as this could get interrupted by the dcf update
            if (currentTime.getSeconds() > 5)
            {
                currentlyDimmed = shouldBeDimmed;
                if (shouldBeDimmed)
                {
                    DimAnimation.start(255, Settings.DISPLAY_DIM_BRIGHTNESS, Settings.DISPLAY_DIM_ANIMATION_DURATION);
                }
                else
                {
                    DimAnimation.start(Settings.DISPLAY_DIM_BRIGHTNESS, 255, Settings.DISPLAY_DIM_ANIMATION_DURATION);
                }
            }
        }
        else
        {
            if (DimAnimation.isRunning())
            {
                DimAnimation.render();
            }
            else
            {
                NixieDisplay.setBrightness(shouldBeDimmed ? Settings.DISPLAY_DIM_BRIGHTNESS : 255);
            }
        }
    }
    else
    {
        NixieDisplay.setBrightness(255);
    }

    NixieDisplay.flush();
}

void loop()
{
    // Update rtc if necessary.
    // Has to be done in main() because interrupts cannot communicate over i2c.
    if (RealTimeClock.tryFetchTime())
    {
        // tryFetchTime yieled a new time state
        if (!RealTimeClock.isTimeValid())
        {
            Serial.println("Unable to fetch current time!");
        }
        else
        {
            const auto &currentTime = RealTimeClock.getTime();
            //if (currentTime.isInitialized())
            //    currentTime.print();
        }
    }

    updateDcf();

    updateDisplay();
}
