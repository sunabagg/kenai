#include "array_occluder3d.h"

void lucidfx::spatial::bindArrayOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::ArrayOccluder>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::ArrayOccluder(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, Occluder3D>(),
        "indicies", sol::property(&ArrayOccluder::getIndices, &ArrayOccluder::setIndices),
        "vertices", sol::property(&ArrayOccluder::getVertices, &ArrayOccluder::setVertices),
        "setArrays", &ArrayOccluder::setArrays,
        "cast", [](lucidfx::core::Resource* instance) {
            return new ArrayOccluder(godot::Object::cast_to<GodotArrayOccluder3D>(instance->getResource()));
        }
    );
}