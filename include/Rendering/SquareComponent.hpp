#pragma once

#include <SDL2/SDL.h>

struct SquareComponent
{
    int side_length;

    SDL_Rect rectangle;
    SDL_Color color;

    SquareComponent(int side_length, int r=0, int g=0, int b=0);
};