#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

struct AnimatedTextRenderer
{
    std::string full_text;
    std::string current_text = "";

    int speed;
    int width = 590;
    
    SDL_Surface* surface_text;
    TTF_Font* font;

    SDL_Rect size_and_pos;

    AnimatedTextRenderer(std::string text, TTF_Font* font, int speed);

    static void render(SDL_Renderer* renderer, AnimatedTextRenderer* txt);
};