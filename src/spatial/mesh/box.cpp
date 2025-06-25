#include "box.h"

void lucidfx::spatial::mesh::bindBox(sol::state& lua) {
    lua.new_usertype<Box>(
        "Box",
        "new", sol::factories(
            []() { return new Box(); }
        ),
        sol::base_classes, sol::bases<Component>(),
        sol::meta_function::garbage_collect, sol::destructor([](Box* b) {  }),
        "size", sol::property(&Box::getSize, &Box::setSize),
        "subdivideDepth", sol::property(&Box::getSubdivideDepth, &Box::setSubdivideDepth),
        "subdivideHeight", sol::property(&Box::getSubdivideHeight, &Box::setSubdivideHeight),
        "subdivideWidth", sol::property(&Box::getSubdivideWidth, &Box::setSubdivideWidth),
        "getFromEntity", [](Entity* entity) {
            return entity->getComponentByT<Box>();
        },
        "cast", [](Component* component) { 
            return dynamic_cast<Box*>(component); 
        }
    );
}