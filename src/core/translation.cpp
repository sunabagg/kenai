#include "translation.h"

void sunaba::core::bindTranslation(sol::state &lua) {
    lua.new_usertype<sunaba::core::Translation>("Translation",
        sol::constructors<sunaba::core::Translation()>(),
        sol::base_classes, sol::bases<sunaba::core::Resource>(),
        "locale", sol::property(
            &sunaba::core::Translation::getLocale,
            &sunaba::core::Translation::setLocale
        ),
        "addMessage", &sunaba::core::Translation::addMessage,
        "addPluralMessage", &sunaba::core::Translation::addPluralMessage,
        "eraseMessage", &sunaba::core::Translation::eraseMessage,
        "getMessage", &sunaba::core::Translation::getMessage,
        "cast", [](Resource* instance) {
            return new Translation(static_cast<GodotTranslation*>(instance->getResource()));
        }
    );
}