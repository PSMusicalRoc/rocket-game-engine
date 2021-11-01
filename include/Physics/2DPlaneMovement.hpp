/**
 * @file 2DPlaneMovement.hpp
 */

#pragma once

#include <bit>

#include "Common/EntCompFunctions.hpp"

struct Movement2DComponent
{
    int speed;
    bool move_left, move_right, move_up, move_down;;

    Movement2DComponent(int speed = 1);

    static void update(Movement2DComponent* comp, SharedPtrEntity ent, double deltatime);
};