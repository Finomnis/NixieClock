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
    static constexpr uint8_t debugMessageVerbosity = 0;

public:
    void init();
    void submitSignal(bool positive, unsigned long startTime, unsigned long duration);
    bool retrieveNewData(DcfTimeData &data, bool &stable);
    unsigned long getLastSyncTime();
    int getReceiveProgress();

private:
    void handleNewTimeData(const DcfTimeData &data);
    void updateData(const DcfTimeData &data, bool stable);

private:
    DcfTimeData currentData;
    volatile bool newDataAvailable{false};
    volatile bool currentDataStable{false};
    volatile unsigned long lastSyncTime{0};

private:
    // Receive buffer
    DcfTimeData incomingData;
    volatile int writePosition{0};
};

extern Dcf77_t Dcf77;