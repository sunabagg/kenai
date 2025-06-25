#include "resource.h"

void lucidfx::core::bindResource(sol::state &lua) {
    lua.new_usertype<lucidfx::core::Resource>("Resource",
        "new", sol::factories(
            []() { return new lucidfx::core::Resource(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject>(),
        "duplicate", &lucidfx::core::Resource::duplicate,
        "emitChanged", &lucidfx::core::Resource::emitChanged,
        "isNull", &lucidfx::core::Resource::isNull,
        "cast", [](Resource* instance) {
            return new Resource(godot::Object::cast_to<GodotResource>(instance->getResource()));
        }
    );
}