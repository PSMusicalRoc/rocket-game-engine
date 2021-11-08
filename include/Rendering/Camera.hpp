#pragma once

#include "Common/EntCompFunctions.hpp"
#include "Common/Globals.hpp"
#include <SDL2/SDL.h>

struct Camera
{
    SharedPtrEntity ent_connected_to;

    float zoom = 1.0f;
    double xpos = 0.0;
    double ypos = 0.0;

    double offset[2] = {0, 0};

    static Camera* GLOBAL_CAMERA;

    Camera(SharedPtrEntity ent_connected_to, float zoom = 1.0f);
    Camera(double xpos, double ypos, float zoom = 1.0f);

    static void update_global_cam_pos();
};

Camera* add_camera_to_entity(SharedPtrEntity ent, float zoom = 1.0f, bool make_global_camera = true);