#include "sphere_occluder3d.h"

void lucidware::spatial::bindSphereOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::SphereOccluder3D>("SphereOccluder3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::SphereOccluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::spatial::Occluder3D>(),
        "radius", sol::property(&SphereOccluder3D::getRadius, &SphereOccluder3D::setRadius),
        "cast", [](lucidware::core::Resource* instance) {
            return new SphereOccluder3D(godot::Object::cast_to<GodotSphereOccluder3D>(instance->getResource()));
        }
    );
}