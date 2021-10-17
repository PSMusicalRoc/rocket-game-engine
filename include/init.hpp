/**
 * @file init.hpp
 * 
 * This file defines init(), which initializes
 * some test entities. This is a file which will
 * probably be replaced with many files (or even
 * a mini little language) that initializes an
 * entity when called/imported/whatever.
 * 
 * @note This will get deprecated when I come up
 * with a better way to initialize specific entities
 */

#pragma once

#include <SDL2/SDL.h>

#include "Common/Entity.hpp"
#include "Common/EntCompFunctions.hpp"

#include "IncludeAllComponents.hpp"

/**
 * @brief Initializes some test entities
 * 
 * @note Will be deprecated soon
 */
void init();