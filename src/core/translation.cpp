#include "translation.h"

void kenai::core::bindTranslation(sol::state &lua) {
    lua.new_usertype<kenai::core::Translation>("Translation",
        "new", sol::factories(
            []() { return new kenai::core::Translation(); }
        ),
        sol::base_classes, sol::bases<kenai::core::Resource>(),
        "locale", sol::property(
            &kenai::core::Translation::getLocale,
            &kenai::core::Translation::setLocale
        ),
        "addMessage", &kenai::core::Translation::addMessage,
        "addPluralMessage", &kenai::core::Translation::addPluralMessage,
        "eraseMessage", &kenai::core::Translation::eraseMessage,
        "getMessage", &kenai::core::Translation::getMessage,
        "getMessageCount", &kenai::core::Translation::getMessageCount,
        "getMessageList", &kenai::core::Translation::getMessageList,
        "getPluralMessage", &kenai::core::Translation::getPluralMessage,
        "getTranslatedMessageList", &kenai::core::Translation::getTranslatedMessageList,
        "cast", [](Resource* instance) {
            return new Translation(godot::Object::cast_to<GodotTranslation>(instance->getResource()));
        }
    );
}