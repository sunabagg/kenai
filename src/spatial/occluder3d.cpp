#include "occluder3d.h"

void kenai::spatial::bindOccluder3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::Occluder3D>("Occluder3D",
        "new", sol::factories(
            []() { return new kenai::spatial::Occluder3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "getIndices", &Occluder3D::getIndices,
        "getVertices", &Occluder3D::getVertices,
        "cast", [](kenai::core::Resource* instance) {
            return new Occluder3D(godot::Object::cast_to<GodotOccluder3D>(instance->getResource()));
        }
    );
}