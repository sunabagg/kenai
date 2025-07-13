#include "moon_console.h"

namespace sunaba::core::io {
    void bindConsole(sol::state& lua) {
        lua.new_usertype<Console>("Console",
            "new", sol::factories(
                []() { return new Console(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element>(),
            "ioInterface", sol::property(
                &Console::getIoInterface,
                &Console::setIoInterface
            ),
            "logs", sol::readonly_property(
                &Console::getLogs
            ),
            "logHandler", sol::property(
                &Console::getLogHandler,
                &Console::setLogHandler
            ),
            "addCommand", &Console::addCommand,
            "getLogColor", &Console::getLogColor
        );
    }
}