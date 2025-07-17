#include "custom_io_interface.h"

namespace sunaba::core::io {
    void bindCustomIoInterface(sol::state& lua) {
        lua.new_usertype<CustomIoInterface>(
            "CustomIoInterface",
            sol::no_constructor,
            sol::base_classes, sol::bases<BaseObject, IoInterface>(),
            "getFileUri", &CustomIoInterface::getFileUri,
            "object", sol::property(
                &CustomIoInterface::getObject,
                &CustomIoInterface::setObject
            )
        );
    }

    std::string CustomIoInterface::getFileUri(const std::string &path) const {
        if (object != sol::lua_nil) {
            if (object["getFileUri"].is<sol::function>() == false) {
                return "";
            }
            auto func = object["getFileUri"].get<sol::function>();
            if (func) {
                auto result = func.call(path);
                std::string resStr = result.get<std::string>();
                return resStr;
            }
        }
        return "";
    }
}