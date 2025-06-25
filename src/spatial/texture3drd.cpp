#include "texture3drd.h"

void lucidware::spatial::bindTexture3DRD(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::Texture3DRD>("Texture3DRD",
        "new", sol::factories(
            []() { return new lucidware::spatial::Texture3DRD(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, Texture3D>(),
        "cast", [](lucidware::core::Resource* instance) {
            return new Texture3DRD(godot::Object::cast_to<GodotTexture3DRD>(instance->getResource()));
        }
    );
}