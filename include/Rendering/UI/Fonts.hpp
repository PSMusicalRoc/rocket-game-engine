#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <unistd.h>
#include <iostream>


struct Fonts
{
    static TTF_Font* ARIAL;
    static TTF_Font* SMALL_ARIAL;
};

bool init_fonts();