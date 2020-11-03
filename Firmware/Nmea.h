#pragma once

#include <Arduino.h>

class Nmea_t
{
public:
    void init();
    void update();
    void processTimeUpdate();

    inline int getHours() { return hoursMsd * 10 + hoursLsd; }
    inline int getMinutes() { return minutesMsd * 10 + minutesLsd; }
    inline int getSeconds() { return secondsMsd * 10 + secondsLsd; }
    inline int getMinutesMsd() { return minutesMsd; }
    inline int getMinutesLsd() { return minutesLsd; }
    inline int getHoursMsd() { return hoursMsd; }
    inline int getHoursLsd() { return hoursLsd; }
    inline int isInitialized() { return initialized; }

private:
    const char *expected = "\r\n$GPRMC,";
    const size_t expected_len = 9;

    static const size_t buffer_size = 15;
    int buffer[buffer_size];
    size_t buffer_pos = 0;

    int hoursMsd = -1;
    int hoursLsd = -1;
    int minutesMsd = -1;
    int minutesLsd = -1;
    int secondsMsd = -1;
    int secondsLsd = -1;
    bool initialized = false;
};

extern Nmea_t Nmea;
