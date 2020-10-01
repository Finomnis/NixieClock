#pragma once

#include <Arduino.h>

#include "RealTimeTimestamp.h"

struct DcfTimeData
{
    RealTimeTimestamp timestamp;
    uint8_t timezone{0};
    unsigned long systemTime;
    bool valid{false};

    void print();
};

class Dcf77_t
{
public:
    void init();
    void submitSignal(bool positive, unsigned long startTime, unsigned long duration);

private:
    DcfTimeData currentData;
    DcfTimeData previousData;
};

extern Dcf77_t Dcf77;