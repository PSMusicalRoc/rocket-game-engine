#pragma once
#include "Common/Globals.hpp"

#include <string>
#include <iostream>

/*


LOG LEVELS ARE STORED IN GLOBALS.HPP


*/

struct Logger
{
    static void log(int log_level, std::string output);
};