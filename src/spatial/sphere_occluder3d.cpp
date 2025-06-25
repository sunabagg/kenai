#include "sphere_occluder3d.h"

void lucidfx::spatial::bindSphereOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::SphereOccluder3D>("SphereOccluder3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::SphereOccluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::spatial::Occluder3D>(),
        "radius", sol::property(&SphereOccluder3D::getRadius, &SphereOccluder3D::setRadius),
        "cast", [](lucidfx::core::Resource* instance) {
            return new SphereOccluder3D(godot::Object::cast_to<GodotSphereOccluder3D>(instance->getResource()));
        }
    );
}