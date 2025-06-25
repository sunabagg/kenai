#include "translation.h"

void lucidware::core::bindTranslation(sol::state &lua) {
    lua.new_usertype<lucidware::core::Translation>("Translation",
        "new", sol::factories(
            []() { return new lucidware::core::Translation(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::Resource>(),
        "locale", sol::property(
            &lucidware::core::Translation::getLocale,
            &lucidware::core::Translation::setLocale
        ),
        "addMessage", &lucidware::core::Translation::addMessage,
        "addPluralMessage", &lucidware::core::Translation::addPluralMessage,
        "eraseMessage", &lucidware::core::Translation::eraseMessage,
        "getMessage", &lucidware::core::Translation::getMessage,
        "getMessageCount", &lucidware::core::Translation::getMessageCount,
        "getMessageList", &lucidware::core::Translation::getMessageList,
        "getPluralMessage", &lucidware::core::Translation::getPluralMessage,
        "getTranslatedMessageList", &lucidware::core::Translation::getTranslatedMessageList,
        "cast", [](Resource* instance) {
            return new Translation(godot::Object::cast_to<GodotTranslation>(instance->getResource()));
        }
    );
}