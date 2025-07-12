#include "resource.h"

void kenai::core::bindResource(sol::state &lua) {
    lua.new_usertype<kenai::core::Resource>("Resource",
        "new", sol::factories(
            []() { return new kenai::core::Resource(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject>(),
        "duplicate", &kenai::core::Resource::duplicate,
        "emitChanged", &kenai::core::Resource::emitChanged,
        "isNull", &kenai::core::Resource::isNull,
        "cast", [](Resource* instance) {
            return new Resource(godot::Object::cast_to<GodotResource>(instance->getResource()));
        }
    );
}