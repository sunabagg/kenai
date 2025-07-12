#include "cubemap.h"

void kenai::spatial::bindCubemap(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::Cubemap>("Cubemap",
        "new", sol::factories(
            []() { return new kenai::spatial::Cubemap(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, kenai::core::TextureLayered, kenai::core::ImageTextureLayered>(),
        "createPlaceholder", &Cubemap::createPlaceholder,
        "cast", [](kenai::core::Resource* instance) {
            return new Cubemap(godot::Object::cast_to<GodotCubemap>(instance->getResource()));
        }
    );
}