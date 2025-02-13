#include "capsule.h"

void newhaven_spatial_mesh::bindCapsule(sol::state& lua) {
    lua.new_usertype<Capsule>(
        "Capsule",
        sol::constructors<Capsule()>(),
        sol::base_classes, sol::bases<Component>(),
        "height", sol::property(&Capsule::getHeight, &Capsule::setHeight),
        "radialSegments", sol::property(&Capsule::getRadialSegments, &Capsule::setRadialSegments),
        "rings", sol::property(&Capsule::getRings, &Capsule::setRings),
        "radius", sol::property(&Capsule::getRadius, &Capsule::setRadius),
        "getFromEntity", [](Entity* entity) {
            Component* component = entity->getComponent("Capsule");
            return static_cast<Capsule*>(component);
        }
    );
}