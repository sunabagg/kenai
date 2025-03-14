#include "array_occluder3d.h"

void sunaba::spatial::bindArrayOccluder3D(sol::state_view& lua) {
    lua.new_usertype<sunaba::spatial::ArrayOccluder3D>("ArrayOccluder3D",
        sol::constructors<ArrayOccluder3D()>(),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, Occluder3D>(),
        "polygon", sol::property(&ArrayOccluder3D::getPolygon, &ArrayOccluder3D::setPolygon),
        "cast", [](sunaba::core::Resource* instance) {
            return new ArrayOccluder3D(godot::Object::cast_to<GodotArrayOccluder3D>(instance->getResource()));
        }
    );
}