#include "box_occluder3d.h"

void kenai::spatial::bindBoxOccluder3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::BoxOccluder>("BoxOccluder3D",
        "new", sol::factories(
            []() { return new kenai::spatial::BoxOccluder(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, Occluder3D>(),
        "size", sol::property(&BoxOccluder::getSize, &BoxOccluder::setSize),
        "cast", [](kenai::core::Resource* instance) {
            return new BoxOccluder(godot::Object::cast_to<GodotBoxOccluder3D>(instance->getResource()));
        }
    );
}