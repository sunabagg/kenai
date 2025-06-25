#include "sphere.h"

void lucidware::spatial::mesh::bindSphere(sol::state& lua) {
    lua.new_usertype<Sphere>(
        "Sphere",
        "new", sol::factories(
            []() { return new Sphere(); }
        ),
        sol::base_classes, sol::bases<Component>(),
        sol::meta_function::garbage_collect, sol::destructor([](Sphere* s) {  }),
        "height", sol::property(&Sphere::getHeight, &Sphere::setHeight),
        "isHemisphere", sol::property(&Sphere::getIsHemisphere, &Sphere::setIsHemisphere),
        "radialSegments", sol::property(&Sphere::getRadialSegments, &Sphere::setRadialSegments),
        "rings", sol::property(&Sphere::getRings, &Sphere::setRings),
        "radius", sol::property(&Sphere::getRadius, &Sphere::setRadius),
        "getFromEntity", [](Entity* entity) {
            Component* component = entity->getComponentByT<Sphere>();
            return dynamic_cast<Sphere*>(component);
        },
        "cast", [](Component* component) { 
            return dynamic_cast<Sphere*>(component); 
        }
    );
}