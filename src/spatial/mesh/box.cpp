#include "box.h"

void newhaven_spatial_mesh::bindBox(sol::state& lua) {
    lua.new_usertype<Box>(
        "Box",
        sol::constructors<Box()>(),
        sol::base_classes, sol::bases<Component>(),
        "size", sol::property(&Box::getSize, &Box::setSize),
        "subdivideDepth", sol::property(&Box::getSubdivideDepth, &Box::setSubdivideDepth),
        "subdivideHeight", sol::property(&Box::getSubdivideHeight, &Box::setSubdivideHeight),
        "subdivideWidth", sol::property(&Box::getSubdivideWidth, &Box::setSubdivideWidth),
        "getFromEntity", [](Entity* entity) {
            Component* component = entity->getComponent("Box");
            return static_cast<Box*>(component);
        }
    );
}