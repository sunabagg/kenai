#include "world3d.h"

void kenai::spatial::bindWorld3D(sol::state_view& lua) {
    lua.new_usertype<World3D>("World3D",
        "new", sol::factories(
            []() { return new World3D(); }
        ),
        sol::base_classes, sol::bases<kenai::core::BaseObject, kenai::core::Resource>(),
        "cameraAttributes", sol::property(&World3D::getCameraAttributes, &World3D::setCameraAttributes),
        "environment", sol::property(&World3D::getEnvironment, &World3D::setEnvironment),
        "cast", [](kenai::core::Resource* res) {
            return new World3D(Object::cast_to<GodotWorld3D>(res->getResource()));
        }
    );
}