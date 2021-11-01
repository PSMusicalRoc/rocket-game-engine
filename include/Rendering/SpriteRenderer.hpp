#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Common/EntCompFunctions.hpp"

#include "Rendering/Spritesheet.hpp"
#include "Rendering/Animations/Animation.hpp"

#include <memory>
#include <map>
#include <string>

typedef std::shared_ptr<Animation> SharedPtrAnim;

struct SpriteRenderer
{
    std::map<std::string, SharedPtrAnim> animations;
    std::string current_animation = "";
    std::string past_animation = "";

    SDL_Texture* rendered_image;
    bool do_clip = false;
    SDL_Rect clip;
    SDL_Rect pos;

    int current_sheet_id = 0;

    SpriteRenderer(std::string anim_name, Animation anim);

    void switch_animation(std::string id);

    static void render(SDL_Renderer* renderer, SpriteRenderer* sprite_renderer, SharedPtrEntity ent);
};

void add_animation_to_spriterenderer(SpriteRenderer* sprite_renderer, std::string anim_name, Animation anim);

void remove_animation_from_spriterenderer(SpriteRenderer* sprite_renderer, std::string id);