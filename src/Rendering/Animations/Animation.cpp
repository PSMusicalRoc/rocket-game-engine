#include "Rendering/Animations/Animation.hpp"

Animation::Animation(Spritesheet spritesheet)
    :spritesheet(spritesheet) {}

Animation::~Animation()
{
    SDL_FreeSurface(spritesheet.spritesheet);
}


/**
 * Plays this animation at frame `frame`. If
 * `frame` < 0, then play from current frame
 * if frame >= 0, play from specified frame
 * 
 * param frame (int): the frame to play from 
 */
void Animation::play(int frame)
{
    if (frame < 0)
    {
        current_frame++;
        if (current_frame >= animation_frames.size())
        {
            current_frame = 0;
        }
    }
    else
    {
        current_frame = frame;
    }
}

void add_frame_to_animation(Animation* anim, SDL_Rect frame)
{
    anim->animation_frames.emplace_back(frame);
}

void remove_frame_from_animation(Animation* anim, int id)
{
    anim->animation_frames.erase(anim->animation_frames.begin() + id);
}