#include "standard_material3d.h"

void kenai::spatial::bindStandardMaterial3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::StandardMaterial3D>("StandardMaterial3D",
        "new", sol::factories(
            []() { return new kenai::spatial::StandardMaterial3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Material, kenai::spatial::BaseMaterial3D>(),
        "cast", [](kenai::core::Resource* instance) {
            return new StandardMaterial3D(godot::Object::cast_to<GodotStandardMaterial3D>(instance->getResource()));
        }
    );
}