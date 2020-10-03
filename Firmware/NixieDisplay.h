#pragma once

#include <Arduino.h>

struct NixieDisplayContent
{
    uint8_t dots = 0;
    int8_t numbers[4] = {-1};
    bool colon = false;
};

class NixieDisplay_t
{
public:
    void init();
    void flush();
    void setNumbers(int8_t n0, int8_t n1, int8_t n2, int8_t n3);
    void setColon(bool on);
    void clearDots();
    void setDot(int8_t dotPos);
    void setDots(uint8_t dots);

private:
    void flushToSerial(const NixieDisplayContent &newFrame) const;
    void flushToShiftReg(const NixieDisplayContent &newFrame) const;
    void writeValuesToShiftRegister(long val1, long val2) const;

private:
    NixieDisplayContent content;
};

extern NixieDisplay_t NixieDisplay;
