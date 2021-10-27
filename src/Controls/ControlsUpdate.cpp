#include "Controls/ControlsUpdate.hpp"

void Controls::update_controls(SDL_Event* event)
{
    EntPtrVector entities = search_for_entities_with_component<ControlsComponent>();

    SDL_Scancode key = event->key.keysym.scancode;

    for (auto entity : entities)
    {
        int id = find_component_in_entity<ControlsComponent>(entity);
        ControlsComponent* controls = std::any_cast<ControlsComponent>(&entity->component_list.at(id));

        if (controls->Controls.find(key) != controls->Controls.end())
        {
            //found it
            controls->Controls.at(key)();
        }
    }
}