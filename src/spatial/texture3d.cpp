#include "texture3d.h"

void kenai::spatial::bindTexture3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::Texture3D>("Texture3D",
        "new", sol::factories(
            []() { return new kenai::spatial::Texture3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, kenai::core::Texture>(),
        "createPlaceholder", &Texture3D::createPlaceholder,
        "getData", &Texture3D::getData,
        "getDepth", &Texture3D::getDepth,
        "getFormat", &Texture3D::getFormat,
        "getHeight", &Texture3D::getHeight,
        "getWidth", &Texture3D::getWidth,
        "hasMipmaps", &Texture3D::hasMipmaps,
        "cast", [](kenai::core::Resource* instance) {
            return new Texture3D(godot::Object::cast_to<GodotTexture3D>(instance->getResource()));
        }
    );
}