/**
 * @file Animation.hpp
 * 
 * This file defines the Animation object,
 * which holds spritesheets and SDL_Rect objects
 * corellating to where on the spritesheet
 * to draw from.
 */

#pragma once
#include "Rendering/Spritesheet.hpp"

#include <SDL2/SDL.h>

#include <vector>


/**
 * This class contains data pertaining
 * to rendering data from spritesheets.
 * Despite its name, it does NOT
 * necessarily have to be an "animation".
 * Rather, this is basically a wrapper
 * for defining what part of a Spritesheet
 * to render when.
 * 
 * @brief An object holding sprite data and
 * rects defining the parts of the spritesheet
 * to use.
 */
struct Animation
{
    /**
     * @brief A vector of SDL_Rects defining the parts
     * of the spritesheet to use each frame.
     */
    std::vector<SDL_Rect> animation_frames;

    /** @brief This animation's Spritesheet object */
    Spritesheet spritesheet;

    /** @brief The current frame of the animation */
    int current_frame = 0;

    /**
     * Animation contstructor. Should be used in tandem
     * with ::add_component_to_entity()
     * 
     * @param spritesheet The spritesheet for this animation
     * to use.
     */
    Animation(Spritesheet spritesheet);

    /**
     * @brief Animation destructor. Should not be called.
     */
    ~Animation();

    /**
     * Called every frame in the
     * SpriteRenderer::render() static function.
     * 
     * @brief Advances the animation by a frame
     * OR sets the animation to a certain frame.
     * 
     * @param frame The frame for this animation to
     * update to. If this is -1, updates to the next
     * frame in Animation::animation_frames.
     */
    void play(int frame);
};

/**
 * Adds a frame to the animation `anim`. The
 * frame is represented by an SDL_Rect defining
 * the part of the spritesheet to draw from.
 * 
 * @brief Adds a frame to the animation.
 * 
 * @param anim The animation to add a frame to
 * @param frame An SDL_Rect representing the
 * frame of the animation
 */
void add_frame_to_animation(Animation* anim, SDL_Rect frame);

/**
 * Removes a frame from the animation `anim`. Instead
 * of passing in the SDL_Rect and searching that way,
 * you pass in the integer location of the frame in
 * the animation vector and it's removed that way.
 * 
 * @brief Removes a frame from the animation.
 * 
 * @param anim the animation to remove a frame from
 * @param id The integer location of the frame to
 * remove
 */
void remove_frame_from_animation(Animation* anim, int id);