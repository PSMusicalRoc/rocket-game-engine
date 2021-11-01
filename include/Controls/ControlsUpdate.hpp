#pragma once

#include "Common/EntCompFunctions.hpp"
#include "Controls/ControlsComponent.hpp"

#include <SDL2/SDL.h>

namespace Controls
{
    void update_keydown(SDL_Event* event);
    void update_keyup(SDL_Event* event);
}