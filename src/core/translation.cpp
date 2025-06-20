#include "translation.h"

void sunaba::core::bindTranslation(sol::state &lua) {
    lua.new_usertype<sunaba::core::Translation>("Translation",
        "new", sol::factories(
            []() { return new sunaba::core::Translation(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::Resource>(),
        "locale", sol::property(
            &sunaba::core::Translation::getLocale,
            &sunaba::core::Translation::setLocale
        ),
        "addMessage", &sunaba::core::Translation::addMessage,
        "addPluralMessage", &sunaba::core::Translation::addPluralMessage,
        "eraseMessage", &sunaba::core::Translation::eraseMessage,
        "getMessage", &sunaba::core::Translation::getMessage,
        "getMessageCount", &sunaba::core::Translation::getMessageCount,
        "getMessageList", &sunaba::core::Translation::getMessageList,
        "getPluralMessage", &sunaba::core::Translation::getPluralMessage,
        "getTranslatedMessageList", &sunaba::core::Translation::getTranslatedMessageList,
        "cast", [](Resource* instance) {
            return new Translation(godot::Object::cast_to<GodotTranslation>(instance->getResource()));
        }
    );
}