#include "camera_attributes_practical.h"

void sunaba::spatial::bindCameraAttributesPractical(sol::state_view& lua) {
    lua.new_usertype<CameraAttributesPractical>("CameraAttributesPractical",
        "new", sol::factories(
            []() { return new CameraAttributesPractical(); }
        ),
        sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, sunaba::spatial::CameraAttributes>(),
        "autoExposureMaxSensitivity", sol::property(&CameraAttributesPractical::getAutoExposureMaxSensitivity, &CameraAttributesPractical::setAutoExposureMaxSensitivity),
        "autoExposureMinSensitivity", sol::property(&CameraAttributesPractical::getAutoExposureMinSensitivity, &CameraAttributesPractical::setAutoExposureMinSensitivity),
        "dofBlurAmount", sol::property(&CameraAttributesPractical::getDofBlurAmount, &CameraAttributesPractical::setDofBlurAmount),
        "dofBlurFarDistance", sol::property(&CameraAttributesPractical::getDofBlurFarDistance, &CameraAttributesPractical::setDofBlurFarDistance),
        "dofBlurFarEnabled", sol::property(&CameraAttributesPractical::getDofBlurFarEnabled, &CameraAttributesPractical::setDofBlurFarEnabled),
        "dofBlurFarTransition", sol::property(&CameraAttributesPractical::getDofBlurFarTransition, &CameraAttributesPractical::setDofBlurFarTransition),
        "dofBlurNearDistance", sol::property(&CameraAttributesPractical::getDofBlurNearDistance, &CameraAttributesPractical::setDofBlurNearDistance),
        "dofBlurNearEnabled", sol::property(&CameraAttributesPractical::getDofBlurNearEnabled, &CameraAttributesPractical::setDofBlurNearEnabled),
        "dofBlurNearTransition", sol::property(&CameraAttributesPractical::getDofBlurNearTransition, &CameraAttributesPractical::setDofBlurNearTransition),
        "cast", [](sunaba::core::Resource* res) {
            return new CameraAttributesPractical(Object::cast_to<GodotCameraAttributesPractical>(res->getResource()));
        }
    );
}