#pragma once

#include "Common/EntCompFunctions.hpp"
#include "Controls/ControlsComponent.hpp"

#include <SDL2/SDL.h>

namespace Controls
{
    void update_controls(SDL_Event* event);
}