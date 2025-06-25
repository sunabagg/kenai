#include "resource.h"

void lucidware::core::bindResource(sol::state &lua) {
    lua.new_usertype<lucidware::core::Resource>("Resource",
        "new", sol::factories(
            []() { return new lucidware::core::Resource(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject>(),
        "duplicate", &lucidware::core::Resource::duplicate,
        "emitChanged", &lucidware::core::Resource::emitChanged,
        "isNull", &lucidware::core::Resource::isNull,
        "cast", [](Resource* instance) {
            return new Resource(godot::Object::cast_to<GodotResource>(instance->getResource()));
        }
    );
}