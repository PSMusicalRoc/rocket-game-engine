/**
 * @file Entity.hpp
 * 
 * This file defines the Entity struct, as well as being
 * the location of the ::GLOBAL_ENTITY_LIST
 */

#pragma once

#include <any>
#include <string>
#include <vector>
#include <memory>


/**
 * This class is basically an empty shell. The entity is
 * supposed to be nothing more than a container for all the
 * components one adds to it.
 * 
 * It holds a unique identifier, known as an EID (Entity ID),
 * as well as a vector containing all the components within the
 * given Entity. It can also be given labels to facilitate
 * Entity classification.
 * 
 * The class also contains the bare minimum in terms of
 * location. It has an x and y value that represents where the
 * entity "is" in 2D space.'
 * 
 * @note Please, PLEASE use ::create_entity() to create an
 * entity, as it will automatically add itself to
 * ::GLOBAL_ENTITY_LIST, as well as creating a shared pointer
 * which helps with memory management.
 * 
 * @brief Entity class
 */
struct Entity
{

    /** @brief The double representation of the entity's X position.*/
    double x_pos = 0;
    /** @brief The double representation of the entity's Y position.*/
    double y_pos = 0;

    /** @brief The unique Entity Identifier assigned to this Entity. */
    std::string eid;
    
    /**
     * This vector holds the unsorted conglomerate of every component attached
     * to this entity. They can be accessed, found, or added through functions
     * in EntCompFunctions.hpp
     * 
     * @brief The vector of components attached to the entity.
     */
    std::vector<std::any> component_list;

    /**
     * Much like Entity::component_list, this is the unsorted conglomerate
     * of all the labels attached to the entity. One can access these
     * labels directly or search for the via the function
     * ::find_entities_by_label()
     * 
     * @brief The vector of labels attached to this entity.
     */
    std::vector<std::string> labels;

    /**
     * @brief DO NOT USE. USE ::create_entity() INSTEAD.
     * 
     * @param x The x position of the new Entity [default=0]
     * @param y The y position of the new Entity [default=0]
     */
    Entity(double x=0, double y=0);
};

/**
 * This function creates a new Entity, makes a shared pointer
 * out of it, and adds that shared pointer to the ::GLOBAL_ENTITY_LIST.
 * Afterwards, it returns the shared pointer that was created.
 * This is the preferred way to create an entity, as it does
 * some automatic things that are VERY important to the backend
 * of the engine.
 * 
 * @brief Creates and returns an instance of a new Entity.
 * 
 * @param x The x position of the new Entity [default=0]
 * @param y The y position of the new Entity [default=0]
 * 
 * @returns A ::SharedPtrEnt of the newly created Entity.
 */
std::shared_ptr<Entity> create_entity(double x=0, double y=0);

typedef std::vector<std::shared_ptr<Entity>> EntPtrVector;

/**
 * This is the central hub of any and all entities created
 * and stored. It will hold the unsorted conglomerate of
 * every single currently instantiated Entity.
 * 
 * @brief Where every single Entity is stored.
 */
extern EntPtrVector GLOBAL_ENTITY_LIST;