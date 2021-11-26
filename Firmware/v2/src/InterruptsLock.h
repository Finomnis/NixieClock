#pragma once

#include <Arduino.h>

class InterruptsLock
{
    inline InterruptsLock()
    {
        noInterrupts();
    }
    inline ~InterruptsLock()
    {
        interrupts();
    }
    // Prevent copy/move
    InterruptsLock(const InterruptsLock &) = delete;
    InterruptsLock(InterruptsLock &&) = delete;
    InterruptsLock &operator=(const InterruptsLock &) = delete;
    InterruptsLock &operator=(InterruptsLock &&) = delete;
};