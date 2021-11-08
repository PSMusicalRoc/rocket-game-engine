/**
 * @file EntCompFunctions.hpp
 * 
 * Contains Functions regarding Component and Entity
 * functionality.
 * 
 * Examples of these include adding and removing components, as well as
 * creating and finding entities. This file holds templates (usually
 * involving components) as well as the declarations of normal functions.
 */


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

/**
 * @brief A vector of shared Entity Pointers.
 */
typedef std::vector<std::shared_ptr<Entity>> EntPtrVector;

/**
 * @brief A shared Entity Pointer.
 */
typedef std::shared_ptr<Entity> SharedPtrEntity;

/*
Entity ID (EID) functions
*/


/**
 * An internal function to generate an entity id. Generates an id based on
 * the given length.
 * 
 * @brief Use "generate_unique_eid()" instead.
 * 
 * @param len An integer containing the length to generate the entity id at.
 * [default = 12]
 * @returns A std::string containing an eid
 */
std::string _generate_eid(int len=12);


/**
 * Generates a unique entity id using the function _generate_eid() as a base. This
 * calls that function repeatedly until it gets a unique entity id (verified by
 * checking the global entity vector), and returns that.
 * 
 * @brief Generates a unique entity id.
 * 
 * @param len An integer containing the length to generate the entity id at.
 * [default = 12]
 * @returns A std::string containing a unique eid
 */
std::string generate_unique_eid(int len=12);

/*
Component Operators
*/



/**
 * Because our vector contains std::any types, we must use a templated function
 * if we want to use the same function to check any and all components.
 * 
 * @brief A Function that checks if an entity has a component, returning true
 * if so.
 * 
 * @tparam T The type of component that should be checked for
 * @param entity A ::SharedPtrEntity object to check for the given component
 * @returns True if the component exists, false if not
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

/**
 * This function adds a component to an entity. To successfully add the component,
 * the entity must NOT already have an instance of that componenet already.
 * 
 * Because our vector contains std::any types, we must use a templated function
 * if we want to use the same function for any and all components.
 * 
 * @brief Adds a component to an entity.
 * 
 * @tparam T The type of component that should be added
 * 
 * @param component An instance of the component to add to the given entity
 * @param entity A ::SharedPtrEntity object to add the component to
 * @returns A pointer to the created component, or nullptr if the component
 * was not created.
 */
template <typename T>
T* add_component_to_entity(T component, SharedPtrEntity entity)
{
    if (!check_if_entity_has_component<T>(entity))
    {
        entity->component_list.emplace_back(std::make_any<T>(component));
        return std::any_cast<T>(&entity->component_list.at(entity->component_list.size() - 1));
    }
    return nullptr;
}

/**
 * This function removes a component from an entity. Of course, to remove the
 * component, the entity must already HAVE that component.
 * 
 * Because our vector contains std::any types, we must use a templated function
 * if we want to use the same function for any and all components.
 * 
 * @brief Removes a component from an entity.
 * 
 * @tparam T The type of component that should be removed
 * 
 * @param entity A ::SharedPtrEntity object to remove the component from
 * @returns True if the component was removed successfully, false if the entity
 * doesn't have an instance of that type of component
 */
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

/**
 * Of course, to find the component's index, the component must already exist
 * in the entity. However, this function handles the case if the component
 * isn't there.
 * 
 * Because our vector contains `std::any` types, we must use a templated function
 * if we want to use the same function for any and all components.
 * 
 * @brief Finds the index of a component of type T in an entity.
 * 
 * @tparam T The type of component that should be removed
 * 
 * @param entity A ::SharedPtrEntity object to find the component in
 * @returns The integer index of the found component, or -1 if the
 * component doesn't exist.
 */
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

/**
 * @note This function could probably use some optimization, as the
 * complexity is kinda stacking up, especially if this ever becomes
 * large scale. Iterating through linearly is giving a really high
 * complexity, and some more optimized algorithm would probably
 * suffice much better.
 * 
 * We're looking through a lot of vectors here, one being the entity
 * vector, and the other being each and every component vector on each
 * and every entity. See note for greater detail.
 * 
 * Because our component vector contains std::any types, we must use a
 * templated functionif we want to use the same function for any and all
 * components.
 * 
 * @brief Finds each entity with a component of type T
 * 
 * @tparam T The type of component to find
 * 
 * @returns An ::EntPtrVector containing every entity with an instance of
 * component type T. Empty if there are none.
 */
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


/**
 * This function is one of three functions that finds an entity based
 * on some kind of identifying factor. This one in particular is very
 * useful if you're looking for one specific entity and you've saved
 * its EID previously, as there is very little room for error. Since
 * EIDs are unique, you should always receive the specific entity you're
 * looking for.
 * 
 * @brief Searches and finds an entity based on its unique Entity Identifier
 * (EID).
 * 
 * @param eid A string with the entity's EID
 * @returns A ::SharedPtrEntity containing the returned entity, or nullptr
 * if the EID doesn't exist yet.
 */
SharedPtrEntity find_entity_by_eid(std::string eid);

/**
 * This function is one of three functions that finds an entity based
 * on some kind of identifying factor. This is probably the second best
 * finding function, as it's fast, however you can't guarantee that the
 * entity you get is the one you want.
 * 
 * @note This does not handle the error state of not
 * finding the entity at the given index. This will be fixed.
 * 
 * @brief Searches and finds an entity based on its index in the
 * ::GLOBAL_ENTITY_LIST
 * 
 * @param ent_index A int containing the index of the entity
 * @returns A ::SharedPtrEntity containing the returned entity.
 */
SharedPtrEntity find_entity_by_position(int ent_index);


/**
 * This function is one of three functions that finds an entity based
 * on some kind of identifying factor. The important part is that this
 * is the *only* finder function that finds a vector of multiple entities
 * and returns that.
 * 
 * @brief Searches and finds entities based on the labels given to them
 * after their creation.
 * 
 * @param label A string representing the label to search for.
 * @returns A ::EntPtrVector of all the entities with that label.
 */
EntPtrVector find_entities_by_label(std::string label);


/**
 * @note Thank you computer science, this code can be optimized.
 * 
 * This function searches linearly through the global entity list to find
 * the entity's location. As noted, this code can be optimized, as this
 * searching algorithm is pretty basic.
 * 
 * @brief Searches the global entity list for the given entity's index.
 * 
 * @param ent The entity to search for
 * @returns The integer index of the found entity, or -1 if the entity was
 * not found.
 */
int find_entity_position(SharedPtrEntity ent);