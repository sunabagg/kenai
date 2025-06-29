#include "service.h"

namespace sunaba::core {
    void bindService(sol::state& lua) {
        lua.new_usertype<Service>("Service", sol::no_constructor);
    }
}