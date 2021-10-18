#include "Rendering/UI/AnimatedTextRenderer.hpp"

AnimatedTextRenderer::AnimatedTextRenderer(std::string text, TTF_Font* font, int speed)
    :full_text(text), font(font), speed(speed) {}

void AnimatedTextRenderer::advance_dialogue()
{
    if (current_text == full_text)
    {
        current_text = "";
        if (current_message_index + 1 >= messages.size())
        {
            current_message_index = -1;
            return;
        }
        else
        {
            current_message_index += 1;
        }
    }
}

void AnimatedTextRenderer::update(AnimatedTextRenderer* txt, double deltatime)
{
    if (txt->current_message_index < 0)
    {
        txt->end_of_dialogue_callback();
        return;
    }

    txt->time_since_last_char_printed += deltatime;

    txt->full_text = txt->messages[txt->current_message_index];

    while (txt->time_since_last_char_printed >= (double)1/(double)txt->speed)
    {
        if (txt->current_text != txt->full_text)
        {
            txt->current_text += txt->full_text.at(txt->current_text.size());
        }
        txt->time_since_last_char_printed -= (double)1/(double)txt->speed;
    }
}

void AnimatedTextRenderer::render(SDL_Renderer* renderer, AnimatedTextRenderer* txt)
{
    if (txt->current_text != "")
    {
        txt->surface_text = TTF_RenderText_Blended_Wrapped(txt->font, txt->current_text.c_str(), {255, 255, 255}, txt->width);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, txt->surface_text);
        SDL_Rect pos = {txt->size_and_pos.x, txt->size_and_pos.y,
                        txt->surface_text->w, txt->surface_text->h};

        SDL_RenderCopy(renderer, texture, NULL, &pos);

        SDL_FreeSurface(txt->surface_text);
        SDL_DestroyTexture(texture);
    }
}
