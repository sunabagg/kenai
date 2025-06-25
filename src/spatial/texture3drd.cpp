#include "texture3drd.h"

void lucidfx::spatial::bindTexture3DRD(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::Texture3DRD>("Texture3DRD",
        "new", sol::factories(
            []() { return new lucidfx::spatial::Texture3DRD(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture, Texture3D>(),
        "cast", [](lucidfx::core::Resource* instance) {
            return new Texture3DRD(godot::Object::cast_to<GodotTexture3DRD>(instance->getResource()));
        }
    );
}