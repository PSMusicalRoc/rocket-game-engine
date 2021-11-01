#include "Physics/PhysicsSystem.hpp"
#include "Logging/Logger.hpp"
#include <iostream>


void physics_update(double deltatime)
{
    EntPtrVector entities = search_for_entities_with_component<GravityComponent>();

    for (SharedPtrEntity ent : entities)
    {
        int component = find_component_in_entity<GravityComponent>(ent);
        GravityComponent* grav_component = std::any_cast<GravityComponent>(&ent->component_list.at(component));
        
        GravityComponent::update_gravity(grav_component, deltatime);

        ent->y_pos += grav_component->current_velocity * deltatime;
        if (ent->y_pos > 1000)
        {
            int pos = find_entity_position(ent);
            GLOBAL_ENTITY_LIST.erase(GLOBAL_ENTITY_LIST.begin() + pos);
            Logger::log(LogLevel::INFO, "Entity deleted");
            continue;
        }
    }

    entities = search_for_entities_with_component<Movement2DComponent>();

    for (SharedPtrEntity ent : entities)
    {
        int component = find_component_in_entity<Movement2DComponent>(ent);
        Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&ent->component_list.at(component));
        
        Movement2DComponent::update(movement, ent, deltatime);
    }
}