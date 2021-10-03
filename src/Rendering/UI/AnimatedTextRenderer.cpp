#include "Rendering/UI/AnimatedTextRenderer.hpp"

AnimatedTextRenderer::AnimatedTextRenderer(std::string text, TTF_Font* font, int speed)
    :full_text(text), font(font), speed(speed) {}

void AnimatedTextRenderer::render(SDL_Renderer* renderer, AnimatedTextRenderer* txt)
{
    for (int i = 0; i < txt->speed; i++)
    {
        if (txt->current_text != txt->full_text)
        {
            txt->current_text += txt->full_text.at(txt->current_text.size());
        }
    }

    txt->surface_text = TTF_RenderText_Blended_Wrapped(txt->font, txt->current_text.c_str(), {255, 255, 255}, txt->width);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, txt->surface_text);
    SDL_Rect pos = {txt->size_and_pos.x, txt->size_and_pos.y,
                    txt->surface_text->w, txt->surface_text->h};

    SDL_RenderCopy(renderer, texture, NULL, &pos);

    SDL_FreeSurface(txt->surface_text);
    SDL_DestroyTexture(texture);
}
