#include "Common/Entity.hpp"

#include "Common/EntCompFunctions.hpp"

#include <stdarg.h>

EntPtrVector GLOBAL_ENTITY_LIST;

Entity::Entity(double x, double y)
{
    this->x_pos = x;
    this->y_pos = y;
    this->eid = generate_unique_eid(5);
}

std::shared_ptr<Entity> create_entity(double x, double y)
{
    Entity entity = Entity(x, y);
    std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>(entity);
    GLOBAL_ENTITY_LIST.emplace_back(shared_entity);
    return shared_entity;
}