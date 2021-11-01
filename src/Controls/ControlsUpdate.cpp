#include "Controls/ControlsUpdate.hpp"

void Controls::update_keydown(SDL_Event* event)
{
    EntPtrVector entities = search_for_entities_with_component<ControlsComponent>();

    SDL_Scancode key = event->key.keysym.scancode;

    for (auto entity : entities)
    {
        int id = find_component_in_entity<ControlsComponent>(entity);
        ControlsComponent* controls = std::any_cast<ControlsComponent>(&entity->component_list.at(id));

        if (controls->KeyDownCallbacks.find(key) != controls->KeyDownCallbacks.end())
        {
            //found it
            call_keydown_callback(controls, key);
        }
    }
}

void Controls::update_keyup(SDL_Event* event)
{
    EntPtrVector entities = search_for_entities_with_component<ControlsComponent>();

    SDL_Scancode key = event->key.keysym.scancode;

    for (auto entity : entities)
    {
        int id = find_component_in_entity<ControlsComponent>(entity);
        ControlsComponent* controls = std::any_cast<ControlsComponent>(&entity->component_list.at(id));

        if (controls->KeyUpCallbacks.find(key) != controls->KeyUpCallbacks.end())
        {
            //found it
            call_keyup_callback(controls, key);
        }
    }
}