#include "Physics/PhysicsSystem.hpp"
#include "Logging/Logger.hpp"
#include <iostream>

void update_gravity(GravityComponent* component, double deltatime)
{
    component->current_velocity = component->current_velocity + component->gravity_constant * deltatime;
}

void physics_update(double deltatime)
{
    EntPtrVector entities = search_for_entities_with_component<GravityComponent>();

    for (SharedPtrEntity ent : entities)
    {
        int component = find_component_in_entity<GravityComponent>(ent);
        GravityComponent* grav_component = std::any_cast<GravityComponent>(&ent->component_list.at(component));
        
        //ent->component_list[component].get();
        update_gravity(grav_component, deltatime);

        ent->y_pos += grav_component->current_velocity * deltatime;
        if (ent->y_pos > 1000)
        {
            int pos = find_entity_position(ent);
            GLOBAL_ENTITY_LIST.erase(GLOBAL_ENTITY_LIST.begin() + pos);
            Logger::log(LogLevel::INFO, "Entity deleted");
            continue;
        }
    }
}