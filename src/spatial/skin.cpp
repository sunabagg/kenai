#include "skin.h"

void kenai::spatial::bindSkin(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::Skin>("Skin",
        "new", sol::factories(
            []() { return new kenai::spatial::Skin(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
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
        "cast", [](kenai::core::Resource* instance) {
            return new Skin(godot::Object::cast_to<GodotSkin>(instance->getResource()));
        }
    );
}