#include "texture_cubemap_rd.h"

void sunaba::core::bindTextureCubemapRD(sol::state &lua) {
    lua.new_usertype<sunaba::core::TextureCubemapRD>("TextureCubemapRD",
        sol::constructors<sunaba::core::TextureCubemapRD()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::core::Texture, sunaba::core::TextureLayered, sunaba::core::TextureLayeredRD>(),
        "cast", [](sunaba::core::Resource* instance) {
            return new TextureCubemapRD(Object::cast_to<GodotTextureCubemapRD*>(instance->getResource()));
        }
    );
}