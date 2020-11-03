#include <Arduino.h>

#include "Pins.h"
#include "NixieDisplay.h"
#include "SineAnimation.h"
#include "Settings.h"
#include "DimAnimation.h"
#include "Nmea.h"

void setup()
{
    Serial.begin(9600);
    PINS.initializePins();
    NixieDisplay.init();
    Nmea.init();
}

void updateNmea()
{
    Nmea.update();
}

void updateDisplay()
{
    // Numbers
    NixieDisplay.setNumbers(Nmea.getHoursMsd(),
                            Nmea.getHoursLsd(),
                            Nmea.getMinutesMsd(),
                            Nmea.getMinutesLsd());

    // Colon
    NixieDisplay.setColon(Nmea.isInitialized());

    // Dots
    if (Nmea.isInitialized())
    {
        SineAnimation.setActive(false);
        NixieDisplay.clearDots();
    }
    else
    {
        // If freshly initialized or not synced for a while, show resync bar
        SineAnimation.setActive(true);
        SineAnimation.update();
    }

    // Dim
    if (Settings.DISPLAY_DIM_AT_NIGHT)
    {
        static bool currentlyDimmed = false;

        uint16_t dayMinutes = Nmea.getMinutes() + 60L * Nmea.getHours();
        bool shouldBeDimmed = Nmea.isInitialized() &&
                              ((Settings.DISPLAY_DIM_START < Settings.DISPLAY_DIM_END)
                                   ? (dayMinutes >= Settings.DISPLAY_DIM_START && dayMinutes < Settings.DISPLAY_DIM_END)
                                   : (dayMinutes >= Settings.DISPLAY_DIM_START || dayMinutes < Settings.DISPLAY_DIM_END));

        if (shouldBeDimmed != currentlyDimmed)
        {
            // Don't do anything for the first 5 seconds of the minute, as this could get interrupted by the dcf update
            if (Nmea.getSeconds() > 5)
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
    updateNmea();
    updateDisplay();
}
