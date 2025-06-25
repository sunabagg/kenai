#include "occluder3d.h"

void lucidware::spatial::bindOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::Occluder3D>("Occluder3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::Occluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "getIndices", &Occluder3D::getIndices,
        "getVertices", &Occluder3D::getVertices,
        "cast", [](lucidware::core::Resource* instance) {
            return new Occluder3D(godot::Object::cast_to<GodotOccluder3D>(instance->getResource()));
        }
    );
}