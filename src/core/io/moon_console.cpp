#include "moon_console.h"

namespace sunaba::core::io {
    void bindConsole(sol::state& lua) {
        lua.new_usertype<Console>("Console",
            "new", sol::factories(
                []() { return new Console(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element>()
        );
    }
}