#include "sphere.h"

void sunaba_spatial_mesh::bindSphere(sol::state& lua) {
    lua.new_usertype<Sphere>(
        "Sphere",
        sol::constructors<Sphere()>(),
        sol::base_classes, sol::bases<Component>(),
        "height", sol::property(&Sphere::getHeight, &Sphere::setHeight),
        "isHemisphere", sol::property(&Sphere::getIsHemisphere, &Sphere::setIsHemisphere),
        "radialSegments", sol::property(&Sphere::getRadialSegments, &Sphere::setRadialSegments),
        "rings", sol::property(&Sphere::getRings, &Sphere::setRings),
        "radius", sol::property(&Sphere::getRadius, &Sphere::setRadius),
        "getFromEntity", [](Entity* entity) {
            Component* component = entity->getComponentByT<Sphere>();
            return static_cast<Sphere*>(component);
        }
    );
}