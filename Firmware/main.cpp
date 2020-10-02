#include <Arduino.h>

#include "RealTimeClock.h"
#include "Dcf77.h"
#include "Pins.h"

namespace
{
} // namespace

void setup()
{
    Serial.begin(9600);
    PINS.initializePins();
    RealTimeClock.init();
    Dcf77.init();
}

void loop()
{
    // Update rtc if necessary.
    // Has to be done in main() because interrupts cannot communicate over i2c.
    if (RealTimeClock.tryFetchTime())
    {
        // tryFetchTime yieled a new time state
        RealTimeTimestamp currentTime;
        if (!RealTimeClock.getTime(currentTime))
        {
            Serial.println("Unable to fetch current time!");
        }
        else
        {
            if (currentTime.isInitialized())
                currentTime.print();
        }
    }
}
