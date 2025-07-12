#include "polygon_occluder3d.h"

void kenai::spatial::bindPolygonOccluder3D(sol::state_view& lua) {
    lua.new_usertype<kenai::spatial::PolygonOccluder3D>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new kenai::spatial::PolygonOccluder3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource, Occluder3D>(),
        "polygon", sol::property(&PolygonOccluder3D::getPolygon, &PolygonOccluder3D::setPolygon),
        "cast", [](kenai::core::Resource* instance) {
            return new PolygonOccluder3D(godot::Object::cast_to<GodotPolygonOccluder3D>(instance->getResource()));
        }
    );
}