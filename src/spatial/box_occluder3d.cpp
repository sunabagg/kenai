#include "box_occluder3d.h"

void lucidware::spatial::bindBoxOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::BoxOccluder>("BoxOccluder3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::BoxOccluder(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, Occluder3D>(),
        "size", sol::property(&BoxOccluder::getSize, &BoxOccluder::setSize),
        "cast", [](lucidware::core::Resource* instance) {
            return new BoxOccluder(godot::Object::cast_to<GodotBoxOccluder3D>(instance->getResource()));
        }
    );
}