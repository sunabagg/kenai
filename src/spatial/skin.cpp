#include "skin.h"

void lucidfx::spatial::bindSkin(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::Skin>("Skin",
        "new", sol::factories(
            []() { return new lucidfx::spatial::Skin(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource>(),
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
        "cast", [](lucidfx::core::Resource* instance) {
            return new Skin(godot::Object::cast_to<GodotSkin>(instance->getResource()));
        }
    );
}