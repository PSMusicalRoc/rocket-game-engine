#pragma once

#include "Common/Entity.hpp"

#include <any>
#include <type_traits>
#include <typeinfo>
#include <vector>
#include <memory>
#include <string>
#include <random>
#include <chrono>

#include <iostream>

typedef std::vector<std::shared_ptr<Entity>> EntPtrVector;
typedef std::shared_ptr<Entity> SharedPtrEntity;

/*
Entity ID (EID) functions
*/

std::string _generate_eid(int len=12);

std::string generate_unique_eid(int len=12);

/*
Component Operators
*/

template <typename T>
bool check_if_entity_has_component(SharedPtrEntity entity)
{
    for (std::any component : entity->component_list)
    {
        if (component.type() == typeid(T))
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool add_component_to_entity(T component, SharedPtrEntity entity)
{
    if (!check_if_entity_has_component<T>(entity))
    {
        entity->component_list.emplace_back(std::make_any<T>(component));
        return true;
    }
    return false;
}

template <typename T>
bool remove_component_from_entity(SharedPtrEntity entity)
{
    for (int i = 0; i < entity->component_list.size(); i++)
    {
        if (typeid(T) == entity->component_list[i].type())
        {
            entity->component_list.erase(entity->component_list.begin() + i);
            return true;
        }
    }
    return false;
}

template <typename T>
int find_component_in_entity(SharedPtrEntity entity)
{
    for (int i = 0; i < entity->component_list.size(); i++)
    {
        if (typeid(T) == entity->component_list[i].type())
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
EntPtrVector search_for_entities_with_component()
{
    EntPtrVector return_vec;
    for (int i = 0; i < GLOBAL_ENTITY_LIST.size(); i++)
    {
        if (find_component_in_entity<T>(GLOBAL_ENTITY_LIST[i]) != -1)
        {
            return_vec.emplace_back(GLOBAL_ENTITY_LIST[i]);
            continue;
        }
    }
    return return_vec;
}

/*
Entity Operators
*/

SharedPtrEntity find_entity_by_eid(std::string eid);

SharedPtrEntity find_entity_by_position(int ent_index);

EntPtrVector find_entities_by_label(std::string label);

int find_entity_position(SharedPtrEntity ent);