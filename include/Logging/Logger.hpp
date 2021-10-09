/**
 * @file Logger.hpp
 * 
 * This file containst the definition for the static
 * struct "Logger". Note that the logging levels are
 * stored in Globals.hpp.
 */

#pragma once
#include "Common/Globals.hpp"

#include <string>
#include <iostream>

/**
 * The struct Logger is a very small static struct. It only has one
 * method, that being Logger::log(). Call this function whenever
 * you want to log something to the console.
 * 
 * @brief The logging class.
 */
struct Logger
{
    /**
     * This function is the sole logging function at the moment.
     * When you call this function, you specify both a log
     * level and an message to actually log to the console. The
     * Globals::log_level attribute defines the lowest log level
     * that can and should be displayed to the console. For instance,
     * if Globals::log_level == LogLevel::WARNING, then only warnings
     * and other more pertinent logging calls (error and fatal) are
     * actually displayed.
     * 
     * @brief The logging function. Call this when you need to
     * log text to the console.
     * 
     * @param log_level An enum input defining the logging
     * level of this function call.
     * @param output The string to log to the console
     */
    static void log(int log_level, std::string output);
};