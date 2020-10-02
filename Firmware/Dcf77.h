#pragma once

#include <Arduino.h>
#include <TimeLib.h>

#include "RealTimeTimestamp.h"

struct DcfTimeData
{
    RealTimeTimestamp timestamp;
    time_t unixTime;
    unsigned long systemTime;
    time_t rtcTime;
    bool rtcTimeValid{false};
    bool valid{false};

    void print() const;
};

class Dcf77_t
{
    static constexpr bool printDebugMessages = false;

public:
    void init();
    void submitSignal(bool positive, unsigned long startTime, unsigned long duration);

private:
    void handleNewTimeData(const DcfTimeData &data);

private:
    DcfTimeData currentData;
    DcfTimeData previousData;
    volatile bool newDataAvailable{false};
};

extern Dcf77_t Dcf77;