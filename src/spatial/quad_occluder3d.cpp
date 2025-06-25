#include "quad_occluder3d.h"

void lucidfx::spatial::bindQuadOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::QuadOccluder3D>("QuadOccluder3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::QuadOccluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, Occluder3D>(),
        "size", sol::property(&QuadOccluder3D::getSize, &QuadOccluder3D::setSize),
        "cast", [](lucidfx::core::Resource* instance) {
            return new QuadOccluder3D(godot::Object::cast_to<GodotQuadOccluder3D>(instance->getResource()));
        }
    );
}