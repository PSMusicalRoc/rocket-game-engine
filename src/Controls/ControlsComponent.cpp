#include "Controls/ControlsComponent.hpp"

void call_keydown_callback(ControlsComponent* controls, SDL_Scancode key)
{
    // Calls the function at key `key`
    controls->KeyDownCallbacks.at(key)();
}

void set_keydown_callback(ControlsComponent* controls, SDL_Scancode key, void(*function)(void))
{
    if (controls->KeyDownCallbacks.find(key) == controls->KeyDownCallbacks.end())
    {
        controls->KeyDownCallbacks.emplace(key, function);
    }
    else
    {
        controls->KeyDownCallbacks.at(key) = function;
    }
}

void remove_keydown_callback(ControlsComponent* controls, SDL_Scancode key)
{
    controls->KeyDownCallbacks.erase(key);
}

void call_keyup_callback(ControlsComponent* controls, SDL_Scancode key)
{
    // Calls the function at key `key`
    controls->KeyUpCallbacks.at(key)();
}

void set_keyup_callback(ControlsComponent* controls, SDL_Scancode key, void(*function)(void))
{
    if (controls->KeyUpCallbacks.find(key) == controls->KeyUpCallbacks.end())
    {
        controls->KeyUpCallbacks.emplace(key, function);
    }
    else
    {
        controls->KeyUpCallbacks.at(key) = function;
    }
}

void remove_keyup_callback(ControlsComponent* controls, SDL_Scancode key)
{
    controls->KeyUpCallbacks.erase(key);
}