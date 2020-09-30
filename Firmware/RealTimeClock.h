#pragma once

#include <Arduino.h>

#include "RealTimeTimestamp.h"

class RealTimeClock_t
{
public:
    void init();
    void getInfo();
    bool getTime(RealTimeTimestamp &t);
};

extern RealTimeClock_t RealTimeClock;