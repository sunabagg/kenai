#include "texture3drd.h"

void sunaba::spatial::bindTexture3DRD(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::Texture3DRD>("Texture3DRD",
        "new", sol::factories(
            []() { return new sunaba::spatial::Texture3DRD(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, Texture3D>(),
        "cast", [](sunaba::core::Resource* instance) {
            return new Texture3DRD(godot::Object::cast_to<GodotTexture3DRD>(instance->getResource()));
        }
    );
}