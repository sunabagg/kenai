#include "sphere_occluder3d.h"

void kenai::spatial::bindSphereOccluder3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::SphereOccluder3D>("SphereOccluder3D",
        "new", sol::factories(
            []() { return new kenai::spatial::SphereOccluder3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::spatial::Occluder3D>(),
        "radius", sol::property(&SphereOccluder3D::getRadius, &SphereOccluder3D::setRadius),
        "cast", [](kenai::core::Resource* instance) {
            return new SphereOccluder3D(godot::Object::cast_to<GodotSphereOccluder3D>(instance->getResource()));
        }
    );
}