#include "Rendering/SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(std::string anim_name, Animation anim)
{
    this->animations.emplace(anim_name, std::make_shared<Animation>(anim));
}

void add_animation_to_spriterenderer(SpriteRenderer* sprite_renderer, std::string anim_name, Animation anim)
{
    sprite_renderer->animations.emplace(anim_name, std::make_shared<Animation>(anim));
}

void remove_animation_from_spriterenderer(SpriteRenderer* sprite_renderer, std::string id)
{
    sprite_renderer->animations.erase(id);
}

void SpriteRenderer::render(SDL_Renderer* renderer, SpriteRenderer* sprite_renderer)
{
    int h, w;

    sprite_renderer->animations.at(sprite_renderer->current_animation)->play(-1);

    Spritesheet& ss = sprite_renderer->animations.at(sprite_renderer->current_animation)->spritesheet;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, ss.spritesheet);
    //SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    //Logger::log(LogLevel::INFO, "W: " + std::to_string(w) + " H: " + std::to_string(h));

    int current_frame = sprite_renderer->animations.at(sprite_renderer->current_animation)->current_frame;

    if (sprite_renderer->do_clip)
    {
        SDL_RenderCopy(renderer, tex,
            &sprite_renderer->animations.at(sprite_renderer->current_animation)->animation_frames[current_frame],
            &sprite_renderer->pos);
    }
    else
    {
        SDL_RenderCopy(renderer, tex, nullptr, &sprite_renderer->pos);
    }
    SDL_DestroyTexture(tex);
}

void SpriteRenderer::switch_animation(std::string id)
{
    this->current_animation = id;
}