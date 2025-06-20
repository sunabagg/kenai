#include "quad_occluder3d.h"

void sunaba::spatial::bindQuadOccluder3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::QuadOccluder3D>("QuadOccluder3D",
        "new", sol::factories(
            []() { return new sunaba::spatial::QuadOccluder3D(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, Occluder3D>(),
        "size", sol::property(&QuadOccluder3D::getSize, &QuadOccluder3D::setSize),
        "cast", [](sunaba::core::Resource* instance) {
            return new QuadOccluder3D(godot::Object::cast_to<GodotQuadOccluder3D>(instance->getResource()));
        }
    );
}