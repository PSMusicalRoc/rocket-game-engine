/**
 * @file PhysicsSystem.hpp
 * 
 * This file only has one major function in it, but it's
 * very important as it handles all of the physics
 * for the game engine every frame.
 */

#pragma once
#include "Common/Entity.hpp"
#include "Common/EntCompFunctions.hpp"
#include "Common/Globals.hpp"

#include "Physics/GravityComponent.hpp"

#include <any>

/**
 * This function does all the major legwork for updating the
 * physics in the game engine. Currently, it iterates through
 * every entity with a specific component, updates those, then
 * finds another vector of entities with a different component,
 * thus repeating the cycle. While this gives great control
 * over what components to update when, this can and will
 * seriously impact performance. Therefore, this function can
 * and will be optimized in the future.
 * 
 * @brief This function updates all the physics in the game
 * every frame. 
 * 
 * @note This function is somewhat nonoptimal and should be
 * revisited at a later date.
 * 
 * @todo Update this function to optimize the searching
 * and iterating.
 * 
 * @param deltatime The time difference between this and
 * the last frame in seconds.
 */
void physics_update(double deltatime);