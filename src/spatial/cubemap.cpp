#include "cubemap.h"

void sunaba::spatial::bindCubemap(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::Cubemap>("Cubemap",
        "new", sol::factories(
            []() { return new sunaba::spatial::Cubemap(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered, sunaba::core::ImageTextureLayered>(),
        "createPlaceholder", &Cubemap::createPlaceholder,
        "cast", [](sunaba::core::Resource* instance) {
            return new Cubemap(godot::Object::cast_to<GodotCubemap>(instance->getResource()));
        }
    );
}