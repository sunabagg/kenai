#include "translation.h"

void lucidfx::core::bindTranslation(sol::state &lua) {
    lua.new_usertype<lucidfx::core::Translation>("Translation",
        "new", sol::factories(
            []() { return new lucidfx::core::Translation(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::Resource>(),
        "locale", sol::property(
            &lucidfx::core::Translation::getLocale,
            &lucidfx::core::Translation::setLocale
        ),
        "addMessage", &lucidfx::core::Translation::addMessage,
        "addPluralMessage", &lucidfx::core::Translation::addPluralMessage,
        "eraseMessage", &lucidfx::core::Translation::eraseMessage,
        "getMessage", &lucidfx::core::Translation::getMessage,
        "getMessageCount", &lucidfx::core::Translation::getMessageCount,
        "getMessageList", &lucidfx::core::Translation::getMessageList,
        "getPluralMessage", &lucidfx::core::Translation::getPluralMessage,
        "getTranslatedMessageList", &lucidfx::core::Translation::getTranslatedMessageList,
        "cast", [](Resource* instance) {
            return new Translation(godot::Object::cast_to<GodotTranslation>(instance->getResource()));
        }
    );
}