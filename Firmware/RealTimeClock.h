#pragma once

#include <Arduino.h>

#include "RealTimeTimestamp.h"

class RealTimeClock_t
{
public:
    void init();
    void getInfo();
    bool getTime(RealTimeTimestamp &t);
    bool tryFetchTime();
    bool setTime(const RealTimeTimestamp &t);

public:
    // needs to be public, as this gets called by an interrupt handler
    void setNewTimeAvailable();

private:
    volatile uint8_t timezone{0};
    volatile bool timeValid{true};
    volatile bool currentTimeValid{false};
    volatile bool newTimeAvailable{false};
    RealTimeTimestamp currentTime;
};

extern RealTimeClock_t RealTimeClock;