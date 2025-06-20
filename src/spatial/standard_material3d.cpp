#include "standard_material3d.h"

void sunaba::spatial::bindStandardMaterial3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::StandardMaterial3D>("StandardMaterial3D",
        "new", sol::factories(
            []() { return new sunaba::spatial::StandardMaterial3D(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Material, sunaba::spatial::BaseMaterial3D>(),
        "cast", [](sunaba::core::Resource* instance) {
            return new StandardMaterial3D(godot::Object::cast_to<GodotStandardMaterial3D>(instance->getResource()));
        }
    );
}