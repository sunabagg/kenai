#include "occluder3d.h"

void lucidfx::spatial::bindOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::Occluder3D>("Occluder3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::Occluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "getIndices", &Occluder3D::getIndices,
        "getVertices", &Occluder3D::getVertices,
        "cast", [](lucidfx::core::Resource* instance) {
            return new Occluder3D(godot::Object::cast_to<GodotOccluder3D>(instance->getResource()));
        }
    );
}