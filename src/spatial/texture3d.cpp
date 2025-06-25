#include "texture3d.h"

void lucidfx::spatial::bindTexture3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::Texture3D>("Texture3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::Texture3D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, lucidfx::core::Texture>(),
        "createPlaceholder", &Texture3D::createPlaceholder,
        "getData", &Texture3D::getData,
        "getDepth", &Texture3D::getDepth,
        "getFormat", &Texture3D::getFormat,
        "getHeight", &Texture3D::getHeight,
        "getWidth", &Texture3D::getWidth,
        "hasMipmaps", &Texture3D::hasMipmaps,
        "cast", [](lucidfx::core::Resource* instance) {
            return new Texture3D(godot::Object::cast_to<GodotTexture3D>(instance->getResource()));
        }
    );
}