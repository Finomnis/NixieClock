#pragma once

struct RealTimeTimestamp
{
    static constexpr uint8_t DATA_LENGTH = 7;
    char data[DATA_LENGTH] = {0, 0, 0, 1, 1, 1, 0};

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
    inline uint8_t getYear();

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

    void print();
};

class RealTimeClock_t
{
public:
    void init();
    void getInfo();
    bool getTime(RealTimeTimestamp &t);
};

extern RealTimeClock_t RealTimeClock;