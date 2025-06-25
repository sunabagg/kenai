#include "array_occluder3d.h"

void lucidware::spatial::bindArrayOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::ArrayOccluder>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::ArrayOccluder(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, Occluder3D>(),
        "indicies", sol::property(&ArrayOccluder::getIndices, &ArrayOccluder::setIndices),
        "vertices", sol::property(&ArrayOccluder::getVertices, &ArrayOccluder::setVertices),
        "setArrays", &ArrayOccluder::setArrays,
        "cast", [](lucidware::core::Resource* instance) {
            return new ArrayOccluder(godot::Object::cast_to<GodotArrayOccluder3D>(instance->getResource()));
        }
    );
}