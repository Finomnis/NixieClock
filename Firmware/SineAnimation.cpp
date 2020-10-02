#include "SineAnimation.h"

#include "NixieDisplay.h"

namespace
{
    constexpr unsigned long period = 1300;
    constexpr int numLights = 8;
    constexpr unsigned long lightTimings2[numLights - 1] = {
        static_cast<unsigned long>(0.23005345616261585 * period / 2),
        static_cast<unsigned long>(0.33333333333333326 * period / 2),
        static_cast<unsigned long>(0.41956937674483374 * period / 2),
        static_cast<unsigned long>(0.5 * period / 2),
        static_cast<unsigned long>(0.5804306232551661 * period / 2),
        static_cast<unsigned long>(0.6666666666666666 * period / 2),
        static_cast<unsigned long>(0.769946543837384 * period / 2),
    };
    constexpr unsigned long lightTimings3[numLights - 1] = {
        static_cast<unsigned long>(0.17223732852152207 * period / 2),
        static_cast<unsigned long>(0.30638941900529726 * period / 2),
        static_cast<unsigned long>(0.407769168894332 * period / 2),
        static_cast<unsigned long>(0.5 * period / 2),
        static_cast<unsigned long>(0.592230831105668 * period / 2),
        static_cast<unsigned long>(0.6936105809947026 * period / 2),
        static_cast<unsigned long>(0.8277626714784779 * period / 2),
    };
    constexpr unsigned long lightTimings4[numLights - 1] = {
        static_cast<unsigned long>(0.1889822365046136 * period / 2),
        static_cast<unsigned long>(0.32732683535398854 * period / 2),
        static_cast<unsigned long>(0.4225771273642583 * period / 2),
        static_cast<unsigned long>(0.5 * period / 2),
        static_cast<unsigned long>(0.5774228726357418 * period / 2),
        static_cast<unsigned long>(0.6726731646460115 * period / 2),
        static_cast<unsigned long>(0.8110177634953863 * period / 2),
    };
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