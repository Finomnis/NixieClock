#include "NixieDisplay.h"

#include "InterruptsLock.h"
#include "Pins.h"

NixieDisplay_t NixieDisplay;

namespace
{
    NixieDisplayContent currentlyShownFrame;
}

void NixieDisplay_t::init()
{
    // Set initial pin values.
    // Clock needs to be low, to set the correct clock phase.
    // Latch needs to be high to let data through. Will get set to low when setting data.
    digitalWrite(PINS.NIXIE_CLK, LOW);
    digitalWrite(PINS.NIXIE_LATCH, HIGH);
    analogWrite(PINS.NIXIE_DIM, 255);
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

    // Display on Serial Port
    flushToSerial(newFrame);

    // Display on Nixie Tubes
    flushToShiftReg(newFrame);
}

void NixieDisplay_t::writeValuesToShiftRegister(long value1, long value2) const
{
    digitalWrite(PINS.NIXIE_LATCH, LOW);

    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value2 & 255);
    value2 = value2 >> 8;
    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value2 & 255);
    value2 = value2 >> 8;
    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value2 & 255);
    value2 = value2 >> 8;
    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value2 & 255);

    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value1 & 255);
    value1 = value1 >> 8;
    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value1 & 255);
    value1 = value1 >> 8;
    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value1 & 255);
    value1 = value1 >> 8;
    shiftOut(PINS.NIXIE_DATA, PINS.NIXIE_CLK, LSBFIRST, value1 & 255);

    digitalWrite(PINS.NIXIE_LATCH, HIGH);
}

static inline void setOutput(long &value, uint8_t bitId)
{
    value |= (1 << (32 - bitId));
}

static inline void renderNumber(long &data, const uint8_t *pinMappings, int8_t value)
{
    if (value < 0 || value > 9)
        return;

    data |= (1L << (32 - pinMappings[value]));
}

static inline void renderDot(long &data, const uint8_t *pinMappings, uint8_t dotsData, uint8_t dotId)
{
    if ((dotsData & (1 << dotId)) == 0)
        return;

    data |= (1L << (32 - pinMappings[dotId]));
}

void NixieDisplay_t::flushToShiftReg(const NixieDisplayContent &newFrame) const
{
    long data1 = 0;
    long data2 = 0;

    constexpr uint8_t PIN_MAPPING_N1[] = {10, 7, 6, 5, 16, 15, 14, 13, 12, 11};
    constexpr uint8_t PIN_MAPPING_N2[] = {27, 24, 23, 22, 21, 20, 19, 18, 29, 28};
    constexpr uint8_t PIN_MAPPING_N3[] = {10, 7, 6, 5, 16, 15, 14, 13, 12, 11};
    constexpr uint8_t PIN_MAPPING_N4[] = {27, 24, 23, 22, 21, 20, 19, 18, 29, 28};
    constexpr uint8_t PIN_MAPPING_DOTS[] = {8, 9, 25, 26, 8, 9, 25, 26};
    constexpr long COLON_PIN = 0x4;

    if (newFrame.colon)
    {
        data1 |= COLON_PIN;
    }

    renderNumber(data1, PIN_MAPPING_N1, newFrame.numbers[0]);
    renderNumber(data1, PIN_MAPPING_N2, newFrame.numbers[1]);
    renderNumber(data2, PIN_MAPPING_N3, newFrame.numbers[2]);
    renderNumber(data2, PIN_MAPPING_N4, newFrame.numbers[3]);

    renderDot(data1, PIN_MAPPING_DOTS, newFrame.dots, 0);
    renderDot(data1, PIN_MAPPING_DOTS, newFrame.dots, 1);
    renderDot(data1, PIN_MAPPING_DOTS, newFrame.dots, 2);
    renderDot(data1, PIN_MAPPING_DOTS, newFrame.dots, 3);
    renderDot(data2, PIN_MAPPING_DOTS, newFrame.dots, 4);
    renderDot(data2, PIN_MAPPING_DOTS, newFrame.dots, 5);
    renderDot(data2, PIN_MAPPING_DOTS, newFrame.dots, 6);
    renderDot(data2, PIN_MAPPING_DOTS, newFrame.dots, 7);

    writeValuesToShiftRegister(data1, data2);
}

void NixieDisplay_t::flushToSerial(const NixieDisplayContent &newFrame) const
{

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