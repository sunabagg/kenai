#include "cubemap.h"

void lucidfx::spatial::bindCubemap(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::Cubemap>("Cubemap",
        "new", sol::factories(
            []() { return new lucidfx::spatial::Cubemap(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered, lucidfx::core::ImageTextureLayered>(),
        "createPlaceholder", &Cubemap::createPlaceholder,
        "cast", [](lucidfx::core::Resource* instance) {
            return new Cubemap(godot::Object::cast_to<GodotCubemap>(instance->getResource()));
        }
    );
}