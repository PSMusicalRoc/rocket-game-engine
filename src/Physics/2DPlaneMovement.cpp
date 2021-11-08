#include "Physics/2DPlaneMovement.hpp"

Movement2DComponent::Movement2DComponent(int speed)
    :speed(speed), move_left(false), move_right(false),
    move_up(false), move_down(false) {}

void Movement2DComponent::update(Movement2DComponent* comp, SharedPtrEntity ent, double deltatime)
{
    if (comp->move_left)
    {
        ent->x_pos -= comp->speed * deltatime;
    }

    if (comp->move_right)
    {
        ent->x_pos += comp->speed * deltatime;
    }

    if (comp->move_up)
    {
        ent->y_pos -= comp->speed * deltatime;
    }

    if (comp->move_down)
   {
        ent->y_pos += comp->speed * deltatime;
    }
}