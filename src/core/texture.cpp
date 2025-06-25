#include "texture.h"

void lucidware::core::bindTexture(sol::state &lua) {
    lua.new_usertype<lucidware::core::Texture>("Texture",
        "new", sol::factories(
            []() { return new lucidware::core::Texture(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "cast", [](Resource* instance) {
            return new Texture(godot::Object::cast_to<GodotTexture>(instance->getResource()));
        }
    );
}