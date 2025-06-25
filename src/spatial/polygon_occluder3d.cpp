#include "polygon_occluder3d.h"

void lucidware::spatial::bindPolygonOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidware::spatial::PolygonOccluder3D>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new lucidware::spatial::PolygonOccluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, Occluder3D>(),
        "polygon", sol::property(&PolygonOccluder3D::getPolygon, &PolygonOccluder3D::setPolygon),
        "cast", [](lucidware::core::Resource* instance) {
            return new PolygonOccluder3D(godot::Object::cast_to<GodotPolygonOccluder3D>(instance->getResource()));
        }
    );
}