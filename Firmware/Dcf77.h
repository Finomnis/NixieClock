#pragma once

#include <Arduino.h>

class Dcf77_t
{
public:
    void init();
    void submitSignal(bool positive, unsigned long startTime, unsigned long duration);

private:
};

extern Dcf77_t Dcf77;