#include "standard_material3d.h"

void lucidware::spatial::bindStandardMaterial3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::StandardMaterial3D>("StandardMaterial3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::StandardMaterial3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Material, lucidware::spatial::BaseMaterial3D>(),
        "cast", [](lucidware::core::Resource* instance) {
            return new StandardMaterial3D(godot::Object::cast_to<GodotStandardMaterial3D>(instance->getResource()));
        }
    );
}