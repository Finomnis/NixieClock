#include <Arduino.h>

#include "RealTimeClock.h"
#include "Dcf77.h"
#include "Pins.h"

namespace
{
    volatile bool realTimeClockChanged = false;

    void realTimeClockChangedHandler()
    {
        realTimeClockChanged = true;
    }

    RealTimeTimestamp currentTime;
} // namespace

void setup()
{
    Serial.begin(9600);
    PINS.initializePins();
    RealTimeClock.init();
    Dcf77.init();

    //attachInterrupt(digitalPinToInterrupt(PINS.REAL_TIME_CLOCK_CHANGED), realTimeClockChangedHandler, FALLING);
}

void loop()
{
    // TODO don't update clock if we have a new timestamp from DCF77
    if (realTimeClockChanged)
    {
        realTimeClockChanged = false;
        if (!RealTimeClock.getTime(currentTime))
        {
            Serial.println("Unable to fetch current time!");
            currentTime = RealTimeTimestamp();
        }

        // TODO do something more useful
        //currentTime.print();
    }
}
