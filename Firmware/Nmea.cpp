#include "Nmea.h"
#include "Settings.h"

void Nmea_t::update()
{
    if (millis() - last_sync > 2000)
    {
        outdated = true;
    }

    if (Serial.available())
    {
        int read = Serial.read();

        if (buffer_pos < expected_len)
        {
            if (read != expected[buffer_pos])
            {
                buffer_pos = 0;
                return;
            }
        }
        else if (buffer_pos >= buffer_size)
        {
            buffer_pos = 0;
            return;
        }
        else if (read < '0' || read > '9')
        {
            buffer_pos = 0;
            return;
        }

        buffer[buffer_pos++] = read;

        if (buffer_pos == buffer_size)
        {
            processTimeUpdate();
            buffer_pos = 0;
        }
    }
}

void Nmea_t::processTimeUpdate()
{
    hoursLsd = buffer[9] - '0';
    hoursLsd *= 10;
    hoursLsd += buffer[10] - '0';
    minutesMsd = buffer[11] - '0';
    minutesLsd = buffer[12] - '0';
    secondsMsd = buffer[13] - '0';
    secondsLsd = buffer[14] - '0';

    hoursLsd += Settings.TIMEZONE;
    while (hoursLsd >= 24)
    {
        hoursLsd -= 24;
    }

    hoursMsd = 0;
    while (hoursLsd >= 10)
    {
        hoursLsd -= 10;
        hoursMsd += 1;
    }

    initialized = true;
    outdated = false;
    last_sync = millis();
}

void Nmea_t::init() {}

Nmea_t Nmea;