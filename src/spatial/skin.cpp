#include "skin.h"

void sunaba::spatial::bindSkin(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::Skin>("Skin",
        "new", sol::factories(
            []() { return new sunaba::spatial::Skin(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
        "addBind", &Skin::addBind,
        "addNamedBind", &Skin::addNamedBind,
        "clearBinds", &Skin::clearBinds,
        "getBindBone", &Skin::getBindBone,
        "getBindCount", &Skin::getBindCount,
        "getBindName", &Skin::getBindName,
        "getBindPose", &Skin::getBindPose,
        "setBindBone", &Skin::setBindBone,
        "setBindCount", &Skin::setBindCount,
        "setBindName", &Skin::setBindName,
        "setBindPose", &Skin::setBindPose,
        "cast", [](sunaba::core::Resource* instance) {
            return new Skin(godot::Object::cast_to<GodotSkin>(instance->getResource()));
        }
    );
}