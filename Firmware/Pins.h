#pragma once

#include <Arduino.h>

struct PINS_t
{
    const uint8_t NIXIE_DIM = PIN_PA5;
    const uint8_t NIXIE_DATA = PIN_PA6;
    const uint8_t NIXIE_LATCH = PIN_PA7;
    const uint8_t NIXIE_CLK = PIN_PB5;

    const uint8_t TIME_ZONE = PIN_PA4;
    const uint8_t NMEA_SYNC = PIN_PC2;

    void initializePins() const
    {
        pinMode(NIXIE_DIM, OUTPUT);
        pinMode(NIXIE_DATA, OUTPUT);
        pinMode(NIXIE_LATCH, OUTPUT);
        pinMode(NIXIE_CLK, OUTPUT);
        pinMode(TIME_ZONE, INPUT);
        pinMode(NMEA_SYNC, INPUT);
    }
};

extern const PINS_t PINS;