#include "RealTimeClock.h"

#include <Arduino.h>
#include <Wire.h>

static constexpr struct
{
    uint8_t CLIENT_ADDR = 0x68;

    // Device register addresses
    uint8_t REG_TIME = 0x00;
    uint8_t REG_CONTROL = 0x0e;
    uint8_t REG_TEMP = 0x11;

    bool read(uint8_t addr, void *target, uint8_t size) const
    {
        Wire.beginTransmission(CLIENT_ADDR);
        if (Wire.write(addr) != 1)
            return false;
        if (Wire.endTransmission() != 0)
            return false;
        if (Wire.requestFrom(CLIENT_ADDR, size) != size)
            return false;

        uint8_t num_read = 0;
        while (Wire.available())
        {
            char c = Wire.read();
            if (num_read < size)
            {
                reinterpret_cast<char *>(target)[num_read] = c;
            }
            num_read += 1;
        }

        return num_read == size;
    }

    bool write(uint8_t addr, void *data, uint8_t size) const
    {
        Wire.beginTransmission(CLIENT_ADDR);
        if (Wire.write(addr) != 1)
            return false;
        if (Wire.write(reinterpret_cast<char *>(data), size) != size)
            return false;

        return Wire.endTransmission() == 0;
    }

    bool write(uint8_t addr, char data) const
    {
        return write(addr, &data, 1);
    }

} DS3231;

void RealTimeClock_t::init()
{
    Wire.begin();
    // Set configuration of DS3231.
    // Enable 1Hz square wave.
    if (!DS3231.write(DS3231.REG_CONTROL, 0b00011000))
    {
        Serial.println("Error: Unable to write configuration!");
        return;
    }

    // Reset time to 'uninitialized'
    RealTimeTimestamp uninitialized_time;
    uninitialized_time.setUninitialized();
    if (!DS3231.write(DS3231.REG_TIME, uninitialized_time.data, RealTimeTimestamp::DATA_LENGTH))
    {
        Serial.println("Error: Unable to initialize time!");
        return;
    }
}

void RealTimeClock_t::getInfo()
{
    char buf[2];
    if (!DS3231.read(DS3231.REG_TEMP, buf, 2))
    {
        Serial.println("Error: Unable to retrieve temperature!");
        return;
    }
    Serial.print("Temperature: ");
    Serial.print(uint8_t(buf[0]));
    Serial.print(".");
    Serial.println(25 * (uint8_t(buf[1]) >> 6));
}

bool RealTimeClock_t::getTime(RealTimeTimestamp &t)
{
    if (!DS3231.read(DS3231.REG_TIME, t.data, RealTimeTimestamp::DATA_LENGTH))
    {
        Serial.println("Error: Unable to retrieve time!");
        return false;
    }
    return true;
}

RealTimeClock_t RealTimeClock;
