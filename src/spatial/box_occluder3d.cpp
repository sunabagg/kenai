#include "box_occluder3d.h"

void sunaba::spatial::bindBoxOccluder3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::BoxOccluder>("BoxOccluder3D",
        "new", sol::factories(
            []() { return new sunaba::spatial::BoxOccluder(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, Occluder3D>(),
        "size", sol::property(&BoxOccluder::getSize, &BoxOccluder::setSize),
        "cast", [](sunaba::core::Resource* instance) {
            return new BoxOccluder(godot::Object::cast_to<GodotBoxOccluder3D>(instance->getResource()));
        }
    );
}