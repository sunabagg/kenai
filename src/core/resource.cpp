#include "resource.h"

void sunaba::core::bindResource(sol::state &lua) {
    lua.new_usertype<sunaba::core::Resource>("Resource",
        sol::constructors<sunaba::core::Resource()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject>(),
        "duplicate", &sunaba::core::Resource::duplicate,
        "emitChanged", &sunaba::core::Resource::emitChanged,
        "cast", [](Resource* instance) {
            return new Resource(dynamic_cast<GodotResource*>(instance->getResource()));
        }
    );
}