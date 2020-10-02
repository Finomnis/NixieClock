#include "SineAnimation.h"

#include "NixieDisplay.h"

namespace
{
    constexpr unsigned long period = 1300;
    constexpr int numLights = 8;
    constexpr unsigned long lightTimings[numLights - 1] = {
        static_cast<unsigned long>(0.125 * period / 2),
        static_cast<unsigned long>(0.30618621784789724 * period / 2),
        static_cast<unsigned long>(0.414578098794425 * period / 2),
        static_cast<unsigned long>(0.5 * period / 2),
        static_cast<unsigned long>(0.585421901205575 * period / 2),
        static_cast<unsigned long>(0.6938137821521028 * period / 2),
        static_cast<unsigned long>(0.875 * period / 2),
    };
} // namespace

SineAnimation_t SineAnimation;

void SineAnimation_t::setActive(bool active)
{
    if (running == active)
        return;

    running = active;
    startTime = millis();
}

void SineAnimation_t::update()
{
    if (!running)
    {
        return;
    }

    unsigned long now = millis();

    unsigned long position = now % period;
    if (position > period / 2)
    {
        position = period - position;
    }

    int lightPos = 0;
    for (int i = 0; i < numLights - 1; i++)
    {
        if (position > lightTimings[i])
        {
            lightPos += 1;
        }
    }

    NixieDisplay.clearDots();
    NixieDisplay.setDot(lightPos);
}