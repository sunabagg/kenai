#include "texture.h"

void lucidfx::core::bindTexture(sol::state &lua) {
    lua.new_usertype<lucidfx::core::Texture>("Texture",
        "new", sol::factories(
            []() { return new lucidfx::core::Texture(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
        "cast", [](Resource* instance) {
            return new Texture(godot::Object::cast_to<GodotTexture>(instance->getResource()));
        }
    );
}