#include "quad_occluder3d.h"

void lucidware::spatial::bindQuadOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::QuadOccluder3D>("QuadOccluder3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::QuadOccluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, Occluder3D>(),
        "size", sol::property(&QuadOccluder3D::getSize, &QuadOccluder3D::setSize),
        "cast", [](lucidware::core::Resource* instance) {
            return new QuadOccluder3D(godot::Object::cast_to<GodotQuadOccluder3D>(instance->getResource()));
        }
    );
}