#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include <vector>

struct AnimatedTextRenderer
{
    std::vector<std::string> messages;
    int current_message_index = 0;
    std::string full_text;
    std::string current_text = "";

    double time_since_last_char_printed = 0;

    // callback for hitting end of dialogue
    void (*end_of_dialogue_callback)(void) = [](){return;};

    int speed;
    int width = 590;
    
    SDL_Surface* surface_text;
    TTF_Font* font;

    SDL_Rect size_and_pos;

    AnimatedTextRenderer(std::string text, TTF_Font* font, int speed);

    void advance_dialogue();

    static void update(AnimatedTextRenderer* txt, double deltatime);
    static void render(SDL_Renderer* renderer, AnimatedTextRenderer* txt);
};