#include "box.h"

void sunaba::spatial::mesh::bindBox(sol::state& lua) {
    lua.new_usertype<std::shared_ptr<Box>>(
        "Box",
        sol::constructors<Box()>(),
        sol::base_classes, sol::bases<std::shared_ptr<SharedObject>, std::shared_ptr<Component>>(),
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