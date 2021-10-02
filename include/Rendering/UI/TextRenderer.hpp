#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

struct TextRenderer
{
    std::string text;
    SDL_Surface* text_rendered;
    SDL_Rect size_and_pos;
    TTF_Font* font;

    TextRenderer(std::string text, TTF_Font* font);
};