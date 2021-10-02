#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

#include "Logging/Logger.hpp"

struct Spritesheet
{
    SDL_Surface* spritesheet;

    Spritesheet(std::string filename);
};