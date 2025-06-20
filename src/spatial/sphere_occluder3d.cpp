#include "sphere_occluder3d.h"

void sunaba::spatial::bindSphereOccluder3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::SphereOccluder3D>("SphereOccluder3D",
        "new", sol::factories(
            []() { return new sunaba::spatial::SphereOccluder3D(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::spatial::Occluder3D>(),
        "radius", sol::property(&SphereOccluder3D::getRadius, &SphereOccluder3D::setRadius),
        "cast", [](sunaba::core::Resource* instance) {
            return new SphereOccluder3D(godot::Object::cast_to<GodotSphereOccluder3D>(instance->getResource()));
        }
    );
}