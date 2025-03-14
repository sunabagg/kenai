#include "cubemap.h"

void sunaba::spatial::bindCubemap(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::Cubemap>("Cubemap",
        sol::base_classes, sol::bases<sunaba::core::ImageTextureLayered>(),
        sol::constructors<Cubemap()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered, sunaba::core::ImageTextureLayered>(),
        "createPlaceholder", &Cubemap::createPlaceholder,
        "cast", [](sunaba::core::Resource* instance) {
            return new Cubemap(godot::Object::cast_to<GodotCubemap>(instance->getResource()));
        }
    );
}