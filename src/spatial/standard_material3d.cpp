#include "standard_material3d.h"

void lucidfx::spatial::bindStandardMaterial3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::StandardMaterial3D>("StandardMaterial3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::StandardMaterial3D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Material, lucidfx::spatial::BaseMaterial3D>(),
        "cast", [](lucidfx::core::Resource* instance) {
            return new StandardMaterial3D(godot::Object::cast_to<GodotStandardMaterial3D>(instance->getResource()));
        }
    );
}