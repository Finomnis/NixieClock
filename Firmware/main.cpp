#include <Arduino.h>

#include "RealTimeClock.h"

void setup()
{
    Serial.begin(115200);
    RealTimeClock.init();
}

int i = 0;

void loop()
{
    delay(1000);
    //Serial.println(i);
    i++;
    RealTimeClock.getInfo();
}
