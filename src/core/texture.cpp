#include "texture.h"

void kenai::core::bindTexture(sol::state &lua) {
    lua.new_usertype<kenai::core::Texture>("Texture",
        "new", sol::factories(
            []() { return new kenai::core::Texture(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "cast", [](Resource* instance) {
            return new Texture(godot::Object::cast_to<GodotTexture>(instance->getResource()));
        }
    );
}