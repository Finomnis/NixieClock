#pragma once

#include <Arduino.h>

struct Settings_t
{
    bool COLON_BLINK_EVERY_SECOND = false;
    bool COLON_BLINK_ON_SYNC = false;
    bool DISPLAY_RENDER_TO_CONSOLE = false;
    bool RESET_RTC_ON_STARTUP = false;
    unsigned long TIME_UNTIL_DCF_ANIMATION_SHOWS_AGAIN = 4L * 60L * 60L * 1000L; // Four Hours (from time zone change to morning)

    // Dimming
    bool DISPLAY_DIM_AT_NIGHT = true;
    uint8_t DISPLAY_DIM_BRIGHTNESS = 15;
    uint16_t DISPLAY_DIM_START = 23 * 60;
    uint16_t DISPLAY_DIM_END = 7 * 60;
    unsigned long DISPLAY_DIM_ANIMATION_DURATION = 40000;
};

extern const Settings_t Settings;