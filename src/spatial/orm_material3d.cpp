#include "orm_material3d.h"

void kenai::spatial::bindOrmMaterial3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::OrmMaterial3D>("OrmMaterial3D",
        "new", sol::factories(
            []() { return new kenai::spatial::OrmMaterial3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Material, kenai::spatial::BaseMaterial3D>(),
        "cast", [](kenai::core::Resource* instance) {
            return new OrmMaterial3D(godot::Object::cast_to<GodotOrmMaterial3D>(instance->getResource()));
        }
    );
}