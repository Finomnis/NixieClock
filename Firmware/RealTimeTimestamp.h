#pragma once

#include <Arduino.h>
#include <TimeLib.h>

struct RealTimeTimestamp
{
    static constexpr uint8_t DATA_LENGTH = 7;
    char data[DATA_LENGTH] = {0};
    uint8_t timezone{0};

    inline uint8_t getSeconds() const
    {
        return getSecondsMsd() * 10 + getSecondsLsd();
    }
    inline uint8_t getMinutes() const
    {
        return getMinutesMsd() * 10 + getMinutesLsd();
    }
    inline uint8_t getHours() const
    {
        return getHoursMsd() * 10 + getHoursLsd();
    }
    inline uint8_t getDayOfWeek() const
    {
        return data[3] & 0b111;
    }
    inline uint8_t getDay() const
    {
        return getDayMsd() * 10 + getDayLsd();
    }
    inline uint8_t getMonth() const
    {
        return getMonthMsd() * 10 + getMonthLsd();
    }
    inline uint16_t getYear() const
    {
        return 2000 + 100 * getCentury() + getYearMsd() * 10 + getYearLsd();
    }
    inline uint8_t getTimezone() const
    {
        return timezone;
    }

    inline uint8_t getSecondsMsd() const
    {
        return (data[0] & 0b1110000) >> 4;
    }
    inline uint8_t getSecondsLsd() const
    {
        return data[0] & 0b1111;
    }
    inline uint8_t getMinutesMsd() const
    {
        return (data[1] & 0b1110000) >> 4;
    }
    inline uint8_t getMinutesLsd() const
    {
        return data[1] & 0b1111;
    }
    inline uint8_t getHoursMsd() const
    {
        return (data[2] & 0b110000) >> 4;
    }
    inline uint8_t getHoursLsd() const
    {
        return data[2] & 0b1111;
    }
    inline uint8_t getDayMsd() const
    {
        return (data[4] & 0b110000) >> 4;
    }
    inline uint8_t getDayLsd() const
    {
        return data[4] & 0b1111;
    }
    inline uint8_t getMonthMsd() const
    {
        return (data[5] & 0b10000) >> 4;
    }
    inline uint8_t getMonthLsd() const
    {
        return data[5] & 0b1111;
    }
    inline uint8_t getYearMsd() const
    {
        return (data[6] & 0b11110000) >> 4;
    }
    inline uint8_t getYearLsd() const
    {
        return data[6] & 0b1111;
    }
    inline uint8_t getCentury() const
    {
        return (data[5] & 0b10000000) >> 7;
    }

    inline bool isInitialized() const
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

    time_t toUnixTime() const;
    void print() const;
};
