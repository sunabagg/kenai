#include "sub_viewport.h"

namespace sunaba::core {
    void bindSubViewport(sol::state& lua) {
        lua.new_usertype<SubViewport>("SubViewport",
            "new", sol::factories(
                []() { return new SubViewport; }
            )
        );
    }
}