#pragma once
#include "Rendering/Spritesheet.hpp"

#include <SDL2/SDL.h>

#include <vector>

struct Animation
{
    std::vector<SDL_Rect> animation_frames;
    Spritesheet spritesheet;

    int current_frame = 0;

    Animation(Spritesheet spritesheet);
    ~Animation();

    void play(int frame);
};

void add_frame_to_animation(Animation* anim, SDL_Rect frame);
void remove_frame_from_animation(Animation* anim, int id);