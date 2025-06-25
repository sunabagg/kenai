#include "orm_material3d.h"

void lucidfx::spatial::bindOrmMaterial3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::OrmMaterial3D>("OrmMaterial3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::OrmMaterial3D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Material, lucidfx::spatial::BaseMaterial3D>(),
        "cast", [](lucidfx::core::Resource* instance) {
            return new OrmMaterial3D(godot::Object::cast_to<GodotOrmMaterial3D>(instance->getResource()));
        }
    );
}