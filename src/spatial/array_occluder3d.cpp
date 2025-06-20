#include "array_occluder3d.h"

void sunaba::spatial::bindArrayOccluder3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::ArrayOccluder>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new sunaba::spatial::ArrayOccluder(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, Occluder3D>(),
        "indicies", sol::property(&ArrayOccluder::getIndices, &ArrayOccluder::setIndices),
        "vertices", sol::property(&ArrayOccluder::getVertices, &ArrayOccluder::setVertices),
        "setArrays", &ArrayOccluder::setArrays,
        "cast", [](sunaba::core::Resource* instance) {
            return new ArrayOccluder(godot::Object::cast_to<GodotArrayOccluder3D>(instance->getResource()));
        }
    );
}