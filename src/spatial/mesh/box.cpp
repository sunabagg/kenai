#include "box.h"

namespace newhaven_spatial_mesh
{
    void bindBox(sol::state& lua) {
        lua.new_usertype<Box>(
            "Box",
            sol::constructors<Box()>(),
            "onInit", &Box::onInit, 
            "onReady", &Box::onReady, 
            "onUpdate", &Box::onUpdate,    
            "onPhysicsUpdate", &Box::onPhysicsUpdate,
            "onFree", &Box::onFree,
            "size", sol::property(&Box::getSize, &Box::setSize),
            "subdivideDepth", sol::property(&Box::getSubdivideDepth, &Box::setSubdivideDepth),
            "subdivideHeight", sol::property(&Box::getSubdivideHeight, &Box::setSubdivideHeight),
            "subdivideWidth", sol::property(&Box::getSubdivideWidth, &Box::setSubdivideWidth));
    }
}