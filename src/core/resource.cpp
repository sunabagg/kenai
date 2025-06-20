#include "resource.h"

void sunaba::core::bindResource(sol::state &lua) {
    lua.new_usertype<sunaba::core::Resource>("Resource",
        "new", sol::factories(
            []() { return new sunaba::core::Resource(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject>(),
        "duplicate", &sunaba::core::Resource::duplicate,
        "emitChanged", &sunaba::core::Resource::emitChanged,
        "isNull", &sunaba::core::Resource::isNull,
        "cast", [](Resource* instance) {
            return new Resource(godot::Object::cast_to<GodotResource>(instance->getResource()));
        }
    );
}