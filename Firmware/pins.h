#pragma once

#include <Arduino.h>

struct PINS_t
{
    const uint8_t REAL_TIME_CLOCK_CHANGED = PIN_PA2;
    const uint8_t DCF77 = PIN_PC2;

    const uint8_t HV_ENABLE = PIN_PA1;

    void initializePins() const
    {
        pinMode(REAL_TIME_CLOCK_CHANGED, INPUT);
        pinMode(DCF77, INPUT);
        pinMode(HV_ENABLE, OUTPUT);
    }
};

extern const PINS_t PINS;