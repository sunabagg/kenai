#include "occluder3d.h"

void sunaba::spatial::bindOccluder3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::Occluder3D>("Occluder3D",
        "new", sol::factories(
            []() { return new sunaba::spatial::Occluder3D(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "getIndices", &Occluder3D::getIndices,
        "getVertices", &Occluder3D::getVertices,
        "cast", [](sunaba::core::Resource* instance) {
            return new Occluder3D(godot::Object::cast_to<GodotOccluder3D>(instance->getResource()));
        }
    );
}