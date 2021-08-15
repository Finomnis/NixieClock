#pragma once

#include <Arduino.h>

class SineAnimation_t
{
public:
    void setActive(bool active);
    void update();

private:
    bool running{false};
    unsigned long startTime;
};

extern SineAnimation_t SineAnimation;