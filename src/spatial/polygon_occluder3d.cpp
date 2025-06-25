#include "polygon_occluder3d.h"

void lucidfx::spatial::bindPolygonOccluder3D(sol::state_view& lua) {
    lua.new_usertype<lucidfx::spatial::PolygonOccluder3D>("ArrayOccluder3D",
        "new", sol::factories(
            []() { return new lucidfx::spatial::PolygonOccluder3D(); }
        ),
        sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, Occluder3D>(),
        "polygon", sol::property(&PolygonOccluder3D::getPolygon, &PolygonOccluder3D::setPolygon),
        "cast", [](lucidfx::core::Resource* instance) {
            return new PolygonOccluder3D(godot::Object::cast_to<GodotPolygonOccluder3D>(instance->getResource()));
        }
    );
}