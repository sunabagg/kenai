#include "texture2drd.h"

void sunaba::core::bindTexture2DRD(sol::state &lua) {
    lua.new_usertype<Texture2DRD>("Texture2DRD",
        sol::constructors<Texture2DRD()>(),
        sol::base_classes, sol::bases<BaseObject, Resource, Texture, Texture2D>()
    );
}