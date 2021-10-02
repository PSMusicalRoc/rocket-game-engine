#include "Common/EntCompFunctions.hpp"

/*
Entity ID (EID) functions
*/

std::string _generate_eid(int len)
{
    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";
    static const unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine string_generator(seed);
    static std::uniform_int_distribution string_distribution(0, 62);

    std::string return_string = "";
    int i = 0;
    while (i < len)
    {
        return_string += characters[string_distribution(string_generator)];
        i++;
    }
    return return_string;
}

std::string generate_unique_eid(int len)
{
    bool is_unique = false;
    std::string return_val;
    while (!is_unique)
    {
        return_val = _generate_eid(len);
        for (SharedPtrEntity ent : GLOBAL_ENTITY_LIST)
        {
            if (ent->eid == return_val)
            {
                break;
            }
        }
        is_unique = true;
    }
    return return_val;
}

/*
Component Operators
*/
/*bool check_if_entity_has_component(int component_enum, SharedPtrEntity entity)
{
    std::vector<Component*> components = entity->component_list;
    for (int i = 0; i < components.size(); i++)
    {
        if (component_enum == components.at(i)->ident)
        {
            return true;
        }
    }
    return false;
}*/

/*
add_component_to_entity is in EntCompFunctions.hpp
*/

/*bool remove_component_from_entity(int component_enum, SharedPtrEntity entity)
{
    std::vector<Component*> components = entity->component_list;
    for (int i = 0; i < components.size(); i++)
    {
        if (component_enum == components.at(i)->ident)
        {
            components.erase(components.begin() + i);
            return true;
        }
    }
    return false;
}*/

/*int find_component_in_entity(int component_enum, SharedPtrEntity entity)
{
    std::vector<Component*> components = entity->component_list;
    for (int i = 0; i < components.size(); i++)
    {
        if (component_enum == components.at(i)->ident)
        {
            return i;
        }
    }
    return components.max_size();
} */

/*EntPtrVector search_for_entities_with_component(int component_enum)
{
    EntPtrVector return_vec;
    for (int i = 0; i < GLOBAL_ENTITY_LIST.size(); i++)
    {
        if (find_component_in_entity(component_enum, GLOBAL_ENTITY_LIST[i])
            != GLOBAL_ENTITY_LIST[i]->component_list.max_size())
        {
            return_vec.emplace_back(GLOBAL_ENTITY_LIST[i]);
        }
    }
    return return_vec;
}*/

/*
Entity Operators
*/

SharedPtrEntity find_entity_by_eid(std::string eid)
{
    if (eid != "")
    {
        for (int i = 0; i < GLOBAL_ENTITY_LIST.size(); i++)
        {
            if (GLOBAL_ENTITY_LIST[i]->eid == eid)
            {
                return GLOBAL_ENTITY_LIST[i];
            }
        }
    }
    return nullptr;
}

SharedPtrEntity find_entity_by_position(int pos)
{

    return GLOBAL_ENTITY_LIST[pos];
}

EntPtrVector find_entities_by_label(std::string label)
{
    EntPtrVector return_vec;
    if (label != "")
    {
        for (int i = 0; i < GLOBAL_ENTITY_LIST.size(); i++)
        {
            for (int j = 0; j < GLOBAL_ENTITY_LIST[i]->labels.size(); j++)
            {
                if (GLOBAL_ENTITY_LIST[i]->labels[j] == label)
                {
                    return_vec.emplace_back(GLOBAL_ENTITY_LIST[i]);
                    break;
                }
            }
        }
    }
    return return_vec;
}

int find_entity_position(SharedPtrEntity ent)
{
    for (int i = 0; i < GLOBAL_ENTITY_LIST.size(); i++)
    {
        if (ent == GLOBAL_ENTITY_LIST.at(i))
        {
            return i;
        }
    }
    return GLOBAL_ENTITY_LIST.max_size();
}