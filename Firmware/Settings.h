#pragma once

struct Settings_t
{
    bool COLON_BLINK_EVERY_SECOND = false;
    bool COLON_BLINK_ON_SYNC = false;
    bool DISPLAY_RENDER_TO_CONSOLE = false;
    bool RESET_RTC_ON_STARTUP = false;
};

extern const Settings_t Settings;