#include "RealTimeTimestamp.h"

void RealTimeTimestamp::print()
{
    Serial.print(getYear());
    Serial.print("-");
    Serial.print(getMonth());
    Serial.print("-");
    Serial.print(getDay());
    Serial.print(" (");
    Serial.print(getDayOfWeek());
    Serial.print(") ");
    Serial.print(getHours());
    Serial.print(":");
    Serial.print(getMinutes());
    Serial.print(":");
    Serial.print(getSeconds());
    if (!isInitialized())
    {
        Serial.print(" (uninitialized)");
    }

    Serial.print(" ");

    for (int i = 0; i < DATA_LENGTH; i++)
    {
        Serial.print(data[i], HEX);
        if (i != DATA_LENGTH - 1)
        {
            Serial.print("-");
        }
    }

    Serial.println();
}