#pragma once
#include "Common/Entity.hpp"
#include "Common/EntCompFunctions.hpp"
#include "Common/Globals.hpp"

#include "Physics/GravityComponent.hpp"

#include <any>

void update_gravity(GravityComponent& component, double deltatime);

void physics_update(double deltatime);