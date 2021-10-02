#include "Logging/Logger.hpp"

void Logger::log(int log_level, std::string output)
{
    if (log_level >= Globals::log_level)
    {
        std::string prefix = "[";
        switch (log_level)
        {
        case LogLevel::INFO:
            prefix += "INFO";
            break;
        case LogLevel::WARNING:
            prefix += "WARN";
            break;
        case LogLevel::ERROR:
            prefix += "ERROR";
            break;
        case LogLevel::FATAL:
            prefix += "FATAL";
            break;
        default:
            break;
        }
        prefix += "]:\t";
        std::cout << prefix << output << std::endl;
    }
}