#pragma once

#include <any>
#include <string>
#include <vector>
#include <memory>


struct Entity
{
    double x_pos = 0;
    double y_pos = 0;

    std::string eid;
    
    std::vector<std::any> component_list;

    std::vector<std::string> labels;

    Entity(double x=0, double y=0);//, labels);

    std::any test;
};

std::shared_ptr<Entity> create_entity(double x=0, double y=0);

typedef std::vector<std::shared_ptr<Entity>> EntPtrVector;

extern EntPtrVector GLOBAL_ENTITY_LIST;