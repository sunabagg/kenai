#ifndef CAMERA_ATTRIBUTES_PHYSICAL_H
#define CAMERA_ATTRIBUTES_PHYSICAL_H

#include <godot_cpp/classes/camera_attributes_physical.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCameraAttributesPhysical godot::CameraAttributesPhysical

#include "camera_attributes.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindCameraAttributesPhysical(sol::state_view& lua);

    class CameraAttributesPhysical : public CameraAttributes {
    private:
        GodotCameraAttributesPhysical* cameraAttributesPhysical = nullptr;
    public:
        CameraAttributesPhysical() {
            setCameraAttributesPhysical(memnew(GodotCameraAttributesPhysical));
        }

        CameraAttributesPhysical(GodotCameraAttributesPhysical* cap) {
            setCameraAttributesPhysical(cap);
        }

        GodotCameraAttributesPhysical* getCameraAttributesPhysical() {
            return cameraAttributesPhysical;
        }

        void setCameraAttributesPhysical(GodotCameraAttributesPhysical* cap) {
            cameraAttributesPhysical = cap;
            cameraAttributesPhysical->reference();
            setResource(cameraAttributesPhysical);
        }

        float getAutoExposureMaxExposureValue() {
            return cameraAttributesPhysical->get_auto_exposure_max_exposure_value();
        }

        void setAutoExposureMaxExposureValue(float maxEv) {
            cameraAttributesPhysical->set_auto_exposure_max_exposure_value(maxEv);
        }

        float getAutoExposureMinExposureValue() {
            return cameraAttributesPhysical->get_auto_exposure_min_exposure_value();
        }

        void setAutoExposureMinExposureValue(float minEv) {
            cameraAttributesPhysical->set_auto_exposure_min_exposure_value(minEv);
        }

        float getExposureAperture() {
            return cameraAttributesPhysical->get_aperture();
        }

        void setExposureAperture(float aperture) {
            cameraAttributesPhysical->set_aperture(aperture);
        }

        float getExposureShutterSpeed() {
            return cameraAttributesPhysical->get_shutter_speed();
        }

        void setExposureShutterSpeed(float shutterSpeed) {
            cameraAttributesPhysical->set_shutter_speed(shutterSpeed);
        }

        float getFrustumFar() {
            return cameraAttributesPhysical->get_far();
        }

        void setFrustumFar(float far) {
            cameraAttributesPhysical->set_far(far);
        }

        float getFrustumFocalLength() {
            return cameraAttributesPhysical->get_focal_length();
        }

        void setFrustumFocalLength(float focalLength) {
            cameraAttributesPhysical->set_focal_length(focalLength);
        }

        float getFrustumFocusDistance() {
            return cameraAttributesPhysical->get_focus_distance();
        }

        void setFrustumFocusDistance(float focusDistance) {
            cameraAttributesPhysical->set_focus_distance(focusDistance);
        }

        float getFrustumNear() {
            return cameraAttributesPhysical->get_near();
        }

        void setFrustumNear(float near) {
            cameraAttributesPhysical->set_near(near);
        }

        float getFov() {
            return cameraAttributesPhysical->get_fov();
        }
    };
}

#endif // CAMERA_ATTRIBUTES_PHYSICAL_H