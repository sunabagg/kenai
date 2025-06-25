#include "orm_material3d.h"

void lucidware::spatial::bindOrmMaterial3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::OrmMaterial3D>("OrmMaterial3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::OrmMaterial3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Material, lucidware::spatial::BaseMaterial3D>(),
        "cast", [](lucidware::core::Resource* instance) {
            return new OrmMaterial3D(godot::Object::cast_to<GodotOrmMaterial3D>(instance->getResource()));
        }
    );
}