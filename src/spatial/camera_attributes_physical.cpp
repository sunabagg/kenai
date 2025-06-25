#include "camera_attributes_physical.h"

void lucidware::spatial::bindCameraAttributesPhysical(sol::state_view& lua) {
    lua.new_usertype<CameraAttributesPhysical>("CameraAttributesPhysical",
        "new", sol::factories(
            []() { return new CameraAttributesPhysical(); }
        ),
        sol::base_classes, sol::bases<lucidware::core::BaseObject, lucidware::core::Resource, lucidware::spatial::CameraAttributes>(),
        "autoExposureMaxExposureValue", sol::property(&CameraAttributesPhysical::getAutoExposureMaxExposureValue, &CameraAttributesPhysical::setAutoExposureMaxExposureValue),
        "autoExposureMinExposureValue", sol::property(&CameraAttributesPhysical::getAutoExposureMinExposureValue, &CameraAttributesPhysical::setAutoExposureMinExposureValue),
        "exposureAperture", sol::property(&CameraAttributesPhysical::getExposureAperture, &CameraAttributesPhysical::setExposureAperture),
        "exposureShutterSpeed", sol::property(&CameraAttributesPhysical::getExposureShutterSpeed, &CameraAttributesPhysical::setExposureShutterSpeed),
        "frustumFar", sol::property(&CameraAttributesPhysical::getFrustumFar, &CameraAttributesPhysical::setFrustumFar),
        "frustumNear", sol::property(&CameraAttributesPhysical::getFrustumNear, &CameraAttributesPhysical::setFrustumNear),
        "frustomFocalLength", sol::property(&CameraAttributesPhysical::getFrustumFocalLength, &CameraAttributesPhysical::setFrustumFocalLength),
        "frustumFocusDistance", sol::property(&CameraAttributesPhysical::getFrustumFocusDistance, &CameraAttributesPhysical::setFrustumFocusDistance),
        "getFov", &CameraAttributesPhysical::getFov,
        "cast", [](lucidware::core::Resource* res) {
            return new CameraAttributesPhysical(Object::cast_to<GodotCameraAttributesPhysical>(res->getResource()));
        }
    );
}