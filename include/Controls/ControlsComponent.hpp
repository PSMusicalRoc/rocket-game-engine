/**
 * @file ControlsComponent.hpp
 */

#pragma once

#include <SDL2/SDL.h>

#include <map>

struct ControlsComponent
{
    std::map<SDL_Scancode, void(*)(void)> KeyDownCallbacks;
    std::map<SDL_Scancode, void(*)(void)> KeyUpCallbacks;

    ControlsComponent() {}
};

void call_keydown_callback(ControlsComponent* controls, SDL_Scancode key);
void set_keydown_callback(ControlsComponent* controls, SDL_Scancode key, void(*function)(void));
void remove_keydown_callback(ControlsComponent* controls, SDL_Scancode key);

void call_keyup_callback(ControlsComponent* controls, SDL_Scancode key);
void set_keyup_callback(ControlsComponent* controls, SDL_Scancode key, void(*function)(void));
void remove_keyup_callback(ControlsComponent* controls, SDL_Scancode key);