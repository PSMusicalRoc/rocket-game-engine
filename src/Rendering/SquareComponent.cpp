#include "Rendering/SquareComponent.hpp"

SquareComponent::SquareComponent(int side_length, int r, int g, int b)
    :side_length(side_length)
{
    rectangle = SDL_Rect();
    color = SDL_Color();
    color.r = r;
    color.g = g;
    color.b = b;
}