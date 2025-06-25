#include "cubemap.h"

void lucidware::spatial::bindCubemap(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::Cubemap>("Cubemap",
        "new", sol::factories(
            []() { return new lucidware::spatial::Cubemap(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::core::Texture, lucidware::core::TextureLayered, lucidware::core::ImageTextureLayered>(),
        "createPlaceholder", &Cubemap::createPlaceholder,
        "cast", [](lucidware::core::Resource* instance) {
            return new Cubemap(godot::Object::cast_to<GodotCubemap>(instance->getResource()));
        }
    );
}