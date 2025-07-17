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
}