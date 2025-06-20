#include "orm_material3d.h"

void sunaba::spatial::bindOrmMaterial3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::OrmMaterial3D>("OrmMaterial3D",
        "new", sol::factories(
            []() { return new sunaba::spatial::OrmMaterial3D(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Material, sunaba::spatial::BaseMaterial3D>(),
        "cast", [](sunaba::core::Resource* instance) {
            return new OrmMaterial3D(godot::Object::cast_to<GodotOrmMaterial3D>(instance->getResource()));
        }
    );
}