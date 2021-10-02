#pragma once

struct Globals
{
    static int screen_width;
    static int screen_height;

    static int log_level;

    static int FPS;
};

enum LogLevel {
    INFO = 0,
    WARNING,
    ERROR,
    FATAL
};