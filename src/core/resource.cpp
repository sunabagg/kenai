#include "resource.h"

void sunaba::core::bindResource(sol::state &lua) {
    lua.new_usertype<sunaba::core::Resource>("Resource",
        sol::constructors<sunaba::core::Resource()>(),
        "duplicate", &sunaba::core::Resource::duplicate,
        "emitChanged", &sunaba::core::Resource::emitChanged
    );
}