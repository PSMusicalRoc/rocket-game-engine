/**
 * @file GravityComponent.hpp
 * 
 * This file holds the definition of the
 * GravityComponent class. This is one of the physics
 * components in the engine.
 */

#pragma once
#include "Common/Entity.hpp"
#include "Common/EntCompFunctions.hpp"

/**
 * This class adds gravity functionality to whatever Entity
 * it's attached to. In simple terms, every frame it stores
 * a new velocity in itself, and changes the Entity's internal
 * positional attributes based on the velocity. Therefore, the
 * Entity itself if moving downward, not specifically just
 * the GravityComponent, as it acts directly on the Entity's
 * actual position.
 * 
 * @brief A component adding gravity functionality to an
 * Entity.
 * 
 * @class Yes
 */
struct GravityComponent
{
    /** @brief The current velocity of the gravity component.
     * Updated every frame.
     */
    float current_velocity = 0.0f;

    /** @brief The contant of gravitational acceleration. */
    float gravity_constant;

    /**
     * Use this in tandem with add_component_to_entity().
     * 
     * @brief Constructor for GravityComponent.
     * 
     * @param gravity_constant The value to set the internal
     * GravityCompoent::gravity_constant to. [default=9.81]
     */
    GravityComponent(float gravity_constant = 9.81f);

    /**
     * This is a function called every frame in PhysicsSystem.cpp.
     * It is not meant to be called outside of that context.
     * 
     * @brief Updates a GravityComponent's velocity attribute.
     */
    static void update_gravity(GravityComponent* component, double deltatime);
};
