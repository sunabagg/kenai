#include "capsule.h"

void sunaba::spatial::mesh::bindCapsule(sol::state& lua) {
    lua.new_usertype<Capsule>(
        "Capsule",
        sol::constructors<Capsule()>(),
        sol::base_classes, sol::bases<std::shared_ptr<SharedObject>, std::shared_ptr<Component>>(),
        sol::meta_function::garbage_collect, sol::destructor([](Capsule* c) {  }),
        "height", sol::property(&Capsule::getHeight, &Capsule::setHeight),
        "radialSegments", sol::property(&Capsule::getRadialSegments, &Capsule::setRadialSegments),
        "rings", sol::property(&Capsule::getRings, &Capsule::setRings),
        "radius", sol::property(&Capsule::getRadius, &Capsule::setRadius),
        "getFromEntity", [](Entity* entity) {
            return entity->getComponentByT<Capsule>();
        },
        "cast", [](Component* component) { 
            return dynamic_cast<Capsule*>(component); 
        }
    );
}