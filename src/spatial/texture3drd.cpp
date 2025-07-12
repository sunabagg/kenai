#include "texture3drd.h"

void kenai::spatial::bindTexture3DRD(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::Texture3DRD>("Texture3DRD",
        "new", sol::factories(
            []() { return new kenai::spatial::Texture3DRD(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture, Texture3D>(),
        "cast", [](kenai::core::Resource* instance) {
            return new Texture3DRD(godot::Object::cast_to<GodotTexture3DRD>(instance->getResource()));
        }
    );
}