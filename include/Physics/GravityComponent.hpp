#pragma once
#include "Common/Entity.hpp"
#include "Common/EntCompFunctions.hpp"

struct GravityComponent
{
    float current_velocity = 0.0f;

    float gravity_constant;

    GravityComponent(float gravity_constant = 9.81f);

    
};
