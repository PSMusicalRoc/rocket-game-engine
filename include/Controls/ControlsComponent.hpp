/**
 * @file ControlsComponent.hpp
 */

#pragma once

#include <SDL2/SDL.h>

#include <map>

struct ControlsComponent
{
    std::map<SDL_Scancode, void(*)(void)> Controls;

    ControlsComponent() {}
};

void call_controls_callback(ControlsComponent* controls, SDL_Scancode key);
void set_control_callback(ControlsComponent* controls, SDL_Scancode key, void(*function)(void));
void remove_control_callback(ControlsComponent* controls, SDL_Scancode key);