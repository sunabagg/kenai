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
            "currentDir", sol::property(
                &Console::getCurrentDir,
                &Console::setCurrentDir
            ),
            "logHandler", sol::property(
                &Console::getLogHandler,
                &Console::setLogHandler
            ),
            "addCommand", &Console::addCommand,
            "getLogColor", &Console::getLogColor,
            "cmd", &Console::cmd,
            "eval", &Console::eval,
            "print", &Console::print,
            "printErr", &Console::printErr,
            "printColor", &Console::printColor,
            "cast", [](Element* e) {
                auto* c = dynamic_cast<Console*>(e);
                if (c != nullptr) {
                    return c;
                }
                MoonConsole* mc = Object::cast_to<MoonConsole>(e->getNode());
                return new Console(mc);
            }
        );
    }
}