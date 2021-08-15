#pragma once

#include <Arduino.h>
#include "NixieDisplay.h"

class DimAnimation_t
{
public:
    inline bool isRunning() { return running; }
    inline void start(uint8_t startValue, uint8_t endValue, unsigned long duration)
    {
        this->startTime = millis();
        this->startValue = startValue;
        this->endValue = endValue;
        this->duration = duration;
        this->running = true;
    }
    inline void render()
    {
        if (!running)
        {
            return;
        }

        unsigned long now = millis();
        if (now < startTime)
        {
            return;
        }
        if (now >= startTime + duration)
        {
            running = false;
            return;
        }

        // Compute animation-relative time
        now -= startTime;

        if (startValue > endValue)
        {
            NixieDisplay.setBrightness(startValue - (now * uint16_t(startValue - endValue)) / duration);
        }
        else
        {
            NixieDisplay.setBrightness(startValue + (now * uint16_t(endValue - startValue)) / duration);
        }
    }

private:
    bool running = false;
    uint8_t startValue;
    uint8_t endValue;
    unsigned long startTime = 0;
    unsigned long duration;
};

extern DimAnimation_t DimAnimation;