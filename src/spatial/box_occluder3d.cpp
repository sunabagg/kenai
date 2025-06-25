#include "box_occluder3d.h"

void lucidfx::spatial::bindBoxOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::BoxOccluder>("BoxOccluder3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::BoxOccluder(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, Occluder3D>(),
        "size", sol::property(&BoxOccluder::getSize, &BoxOccluder::setSize),
        "cast", [](lucidfx::core::Resource* instance) {
            return new BoxOccluder(godot::Object::cast_to<GodotBoxOccluder3D>(instance->getResource()));
        }
    );
}