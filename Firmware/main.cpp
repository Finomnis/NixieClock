#include <Arduino.h>

#include "RealTimeClock.h"
#include "Dcf77.h"
#include "Pins.h"

namespace
{
} // namespace

void setup()
{
    Serial.begin(115200);
    PINS.initializePins();
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

        // TODO LED on

        // Idle wait to sync point
        while (millis() < syncTime)
        {
        }

        // Sync
        RealTimeClock.setTime(t);
        Serial.println("Synced!");

        // TODO LED off
    }
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

    updateDcf();
}
