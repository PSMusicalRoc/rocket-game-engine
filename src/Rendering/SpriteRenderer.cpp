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

void SpriteRenderer::render(SDL_Renderer* renderer, SpriteRenderer* sprite_renderer, SharedPtrEntity ent)
{
    sprite_renderer->animations.at(sprite_renderer->current_animation)->play(-1);

    Spritesheet& ss = sprite_renderer->animations.at(sprite_renderer->current_animation)->spritesheet;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, ss.spritesheet);
    //SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

    int current_frame = sprite_renderer->animations.at(sprite_renderer->current_animation)->current_frame;

    SDL_Rect output_pos = { sprite_renderer->pos.x + ent->x_pos,
                            sprite_renderer->pos.y + ent->y_pos,
                            sprite_renderer->pos.w,
                            sprite_renderer->pos.h};

    if (sprite_renderer->do_clip)
    {
        SDL_RenderCopy(renderer, tex,
            &sprite_renderer->animations.at(sprite_renderer->current_animation)->animation_frames[current_frame],
            &output_pos);
    }
    else
    {
        SDL_RenderCopy(renderer, tex, nullptr, &output_pos);
    }
    SDL_DestroyTexture(tex);
}

void SpriteRenderer::switch_animation(std::string id)
{
    this->current_animation = id;
}