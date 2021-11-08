#include "Rendering/Camera.hpp"

Camera* Camera::GLOBAL_CAMERA = new Camera(0, 0, 1.0f);

Camera::Camera(SharedPtrEntity ent_connected_to, float zoom)
    :ent_connected_to(ent_connected_to), zoom(zoom) {}

Camera::Camera(double xpos, double ypos, float zoom)
    :xpos(xpos), ypos(ypos), zoom(zoom) { ent_connected_to = nullptr; }

Camera* add_camera_to_entity(SharedPtrEntity ent, float zoom, bool make_global_camera)
{
    Camera* cam = add_component_to_entity<Camera>(Camera(ent, zoom), ent);
    if (make_global_camera)
    {
        Camera::GLOBAL_CAMERA = cam;
    }

    return cam;
}

void Camera::update_global_cam_pos()
{
    if (Camera::GLOBAL_CAMERA->ent_connected_to != nullptr)
        {
            Camera::GLOBAL_CAMERA->xpos = Camera::GLOBAL_CAMERA->ent_connected_to->x_pos + Camera::GLOBAL_CAMERA->offset[0] - (.5 * Globals::screen_width);
            Camera::GLOBAL_CAMERA->ypos = Camera::GLOBAL_CAMERA->ent_connected_to->y_pos + Camera::GLOBAL_CAMERA->offset[1] - (.5 * Globals::screen_height);
        }
}