#include "moon_console.h"

namespace sunaba::core::io {
    void bindConsole(sol::state& lua) {
        lua.new_usertype<Console>("Console");
    }
}