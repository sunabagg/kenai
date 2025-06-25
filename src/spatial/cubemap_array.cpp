#include "cubemap_array.h"

void lucidfx::spatial::bindCubemapArray(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::CubemapArray>("CubemapArray",
        "new", sol::factories(
            []() { return new lucidfx::spatial::CubemapArray(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, lucidfx::core::TextureLayered, lucidfx::core::ImageTextureLayered>(),
        "createPlaceholder", &CubemapArray::createPlaceholder,
        "cast", [](lucidfx::core::Resource* instance) {
            return new CubemapArray(godot::Object::cast_to<GodotCubemapArray>(instance->getResource()));
        }
    );
}