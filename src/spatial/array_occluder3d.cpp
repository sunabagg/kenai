#include "array_occluder3d.h"

void kenai::spatial::bindArrayOccluder3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::ArrayOccluder>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new kenai::spatial::ArrayOccluder(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, Occluder3D>(),
        "indicies", sol::property(&ArrayOccluder::getIndices, &ArrayOccluder::setIndices),
        "vertices", sol::property(&ArrayOccluder::getVertices, &ArrayOccluder::setVertices),
        "setArrays", &ArrayOccluder::setArrays,
        "cast", [](kenai::core::Resource* instance) {
            return new ArrayOccluder(godot::Object::cast_to<GodotArrayOccluder3D>(instance->getResource()));
        }
    );
}