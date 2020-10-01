#pragma once

#include <Arduino.h>

struct RealTimeTimestamp
{
    static constexpr uint8_t DATA_LENGTH = 7;
    char data[DATA_LENGTH] = {0};

    inline uint8_t getSeconds()
    {
        return getSecondsMsd() * 10 + getSecondsLsd();
    }
    inline uint8_t getMinutes()
    {
        return getMinutesMsd() * 10 + getMinutesLsd();
    }
    inline uint8_t getHours()
    {
        return getHoursMsd() * 10 + getHoursLsd();
    }
    inline uint8_t getDayOfWeek()
    {
        return data[3] & 0b111;
    }
    inline uint8_t getDay()
    {
        return getDayMsd() * 10 + getDayLsd();
    }
    inline uint8_t getMonth()
    {
        return getMonthMsd() * 10 + getMonthLsd();
    }
    inline uint16_t getYear()
    {
        return 2000 + 100 * getCentury() + getYearMsd() * 10 + getYearLsd();
    }

    inline uint8_t getSecondsMsd()
    {
        return (data[0] & 0b1110000) >> 4;
    }
    inline uint8_t getSecondsLsd()
    {
        return data[0] & 0b1111;
    }
    inline uint8_t getMinutesMsd()
    {
        return (data[1] & 0b1110000) >> 4;
    }
    inline uint8_t getMinutesLsd()
    {
        return data[1] & 0b1111;
    }
    inline uint8_t getHoursMsd()
    {
        return (data[2] & 0b110000) >> 4;
    }
    inline uint8_t getHoursLsd()
    {
        return data[2] & 0b1111;
    }
    inline uint8_t getDayMsd()
    {
        return (data[4] & 0b110000) >> 4;
    }
    inline uint8_t getDayLsd()
    {
        return data[4] & 0b1111;
    }
    inline uint8_t getMonthMsd()
    {
        return (data[5] & 0b10000) >> 4;
    }
    inline uint8_t getMonthLsd()
    {
        return data[5] & 0b1111;
    }
    inline uint8_t getYearMsd()
    {
        return (data[6] & 0b11110000) >> 4;
    }
    inline uint8_t getYearLsd()
    {
        return data[6] & 0b1111;
    }
    inline uint8_t getCentury()
    {
        return (data[5] & 0b10000000) >> 7;
    }

    inline bool isInitialized()
    {
        return (data[2] & 0b1000000) == 0;
    }

    inline void setUninitialized()
    {
        data[2] |= 0b1000000;
    }

    // Setters for dcf
    inline char &secondsByte()
    {
        return data[0];
    }
    inline char &minutesByte()
    {
        return data[1];
    }
    inline char &hoursByte()
    {
        return data[2];
    }
    inline char &dayOfWeekByte()
    {
        return data[3];
    }
    inline char &dayByte()
    {
        return data[4];
    }
    inline char &monthByte()
    {
        return data[5];
    }
    inline char &yearByte()
    {
        return data[6];
    }

    void print();
};
