#pragma once
#include <SDL2/SDL.h>

#include "Common/Entity.hpp"
#include "Common/EntCompFunctions.hpp"

#include "Rendering/UI/TextRenderer.hpp"
#include "Rendering/UI/Fonts.hpp"

#include "Rendering/SquareComponent.hpp"
#include "Rendering/SpriteRenderer.hpp"

#include <any>

void update_squares(SquareComponent* sqr, SharedPtrEntity entity);

void render(SDL_Renderer* renderer);

void render_ui(SDL_Renderer* renderer);