#include "Controls/ControlsComponent.hpp"

void call_controls_callback(ControlsComponent* controls, SDL_Scancode key)
{
    // Calls the function at key `key`
    controls->Controls.at(key)();
}

void set_control_callback(ControlsComponent* controls, SDL_Scancode key, void(*function)(void))
{
    if (controls->Controls.find(key) == controls->Controls.end())
    {
        controls->Controls.emplace(key, function);
    }
    else
    {
        controls->Controls.at(key) = function;
    }
}

void remove_control_callback(ControlsComponent* controls, SDL_Scancode key)
{
    controls->Controls.erase(key);
}