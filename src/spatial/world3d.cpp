#include "world3d.h"

void lucidware::spatial::bindWorld3D(sol::state_view& lua) {
    lua.new_usertype<World3D>("World3D",
        "new", sol::factories(
            []() { return new World3D(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource>(),
        "cameraAttributes", sol::property(&World3D::getCameraAttributes, &World3D::setCameraAttributes),
        "environment", sol::property(&World3D::getEnvironment, &World3D::setEnvironment),
        "cast", [](lucidware::core::Resource* res) {
            return new World3D(Object::cast_to<GodotWorld3D>(res->getResource()));
        }
    );
}