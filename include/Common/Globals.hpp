/**
 * @file Globals.hpp
 * 
 * This defines a bunch of global values used all over
 * the program. Included here are things like ::screen_width
 * and ::screen_height, as well as the default logging level,
 * the target FPS, and other stuff.
 */

#pragma once

struct Globals
{
    /** @brief The width of the window */
    static int screen_width;
    /** @brief The height of the window */
    static int screen_height;

    /** @brief The lowest log level to display, used in the Logger class */
    static int log_level;

    /** @brief The target FPS for the game to run at. */
    static int FPS;
};

/** @brief The enum defining the logging levels. */
enum LogLevel {
    INFO = 0,
    WARNING,
    ERROR,
    FATAL
};