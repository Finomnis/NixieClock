#include "NixieDisplay.h"

#include "InterruptsLock.h"

NixieDisplay_t NixieDisplay;

namespace
{
    NixieDisplayContent currentlyShownFrame;
}

void NixieDisplay_t::setNumbers(int8_t n0, int8_t n1, int8_t n2, int8_t n3)
{
    content.numbers[0] = n0;
    content.numbers[1] = n1;
    content.numbers[2] = n2;
    content.numbers[3] = n3;
}

void NixieDisplay_t::setColon(bool on)
{
    content.colon = on;
}

void NixieDisplay_t::clearDots()
{
    content.dots = 0;
}

void NixieDisplay_t::setDot(int8_t dotPos)
{
    content.dots |= (1 << dotPos);
}

void NixieDisplay_t::setDots(uint8_t dots)
{
    content.dots = dots;
}

void NixieDisplay_t::flush()
{
    NixieDisplayContent newFrame;
    {
        InterruptsLock lock();
        newFrame = content;
    }

    // Compare old and new frame. If nothing changed, don't redraw.
    if (currentlyShownFrame.colon == newFrame.colon &&
        currentlyShownFrame.dots == newFrame.dots &&
        currentlyShownFrame.numbers[0] == newFrame.numbers[0] &&
        currentlyShownFrame.numbers[1] == newFrame.numbers[1] &&
        currentlyShownFrame.numbers[2] == newFrame.numbers[2] &&
        currentlyShownFrame.numbers[3] == newFrame.numbers[3])
    {
        return;
    }

    // Store new display state
    currentlyShownFrame = newFrame;

    // Update display
    Serial.print("\r");

    if (newFrame.numbers[0] >= 0 && newFrame.numbers[0] <= 9)
    {
        Serial.print(newFrame.numbers[0]);
    }
    else
    {
        Serial.print(" ");
    }

    if (newFrame.numbers[1] >= 0 && newFrame.numbers[1] <= 9)
    {
        Serial.print(newFrame.numbers[1]);
    }
    else
    {
        Serial.print(" ");
    }

    Serial.print(newFrame.colon ? ":" : " ");

    if (newFrame.numbers[2] >= 0 && newFrame.numbers[2] <= 9)
    {
        Serial.print(newFrame.numbers[2]);
    }
    else
    {
        Serial.print(" ");
    }

    if (newFrame.numbers[3] >= 0 && newFrame.numbers[3] <= 9)
    {
        Serial.print(newFrame.numbers[3]);
    }
    else
    {
        Serial.print(" ");
    }

    Serial.print(" ");

    for (int i = 0; i < 8; i++)
    {
        bool dotValue = ((newFrame.dots & (1 << i)) != 0);
        Serial.print(dotValue ? "." : " ");
    }

    Serial.print(" ");
}