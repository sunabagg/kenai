#include "texture2drd.h"

void lucidfx::core::bindTexture2DRD(sol::state &lua) {
    lua.new_usertype<Texture2DRD>("Texture2DRD",
        "new", sol::factories(
            []() { return new Texture2DRD(); }
        ),
        sol::base_classes, sol::bases<BaseObject, Resource, Texture, Texture2D>(),
        "cast", [](Resource* instance) {
            return new Texture2DRD(godot::Object::cast_to<GodotTexture2DRD>(instance->getResource()));
        }
    );
}