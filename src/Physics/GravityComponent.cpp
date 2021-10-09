#include "Physics/GravityComponent.hpp"

GravityComponent::GravityComponent(float gravity_constant)
    :gravity_constant(gravity_constant) {}


void GravityComponent::update_gravity(GravityComponent* component, double deltatime)
{
    component->current_velocity = component->current_velocity + component->gravity_constant * deltatime;
}