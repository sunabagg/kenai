#include "service.h"

namespace kenai::core {
    void bindService(sol::state& lua) {
        lua.new_usertype<Service>("Service", sol::no_constructor);
    }
}