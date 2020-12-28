#pragma once

#include <Arduino.h>

struct PINS_t
{
    const uint8_t REAL_TIME_CLOCK_CHANGED = PIN_PA2;

    const uint8_t NIXIE_DIM = PIN_PA5;
    const uint8_t NIXIE_DATA = PIN_PA6;
    const uint8_t NIXIE_LATCH = PIN_PA7;
    const uint8_t NIXIE_CLK = PIN_PB5;

    void initializePins() const
    {
        pinMode(REAL_TIME_CLOCK_CHANGED, INPUT);
        pinMode(NIXIE_DIM, OUTPUT);
        pinMode(NIXIE_DATA, OUTPUT);
        pinMode(NIXIE_LATCH, OUTPUT);
        pinMode(NIXIE_CLK, OUTPUT);
    }
};

extern const PINS_t PINS;