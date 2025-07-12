#include "quad_occluder3d.h"

void kenai::spatial::bindQuadOccluder3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::QuadOccluder3D>("QuadOccluder3D",
        "new", sol::factories(
            []() { return new kenai::spatial::QuadOccluder3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, Occluder3D>(),
        "size", sol::property(&QuadOccluder3D::getSize, &QuadOccluder3D::setSize),
        "cast", [](kenai::core::Resource* instance) {
            return new QuadOccluder3D(godot::Object::cast_to<GodotQuadOccluder3D>(instance->getResource()));
        }
    );
}