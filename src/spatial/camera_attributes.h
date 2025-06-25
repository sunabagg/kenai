#ifndef CAMERA_ATTRIBUTES_H
#define CAMERA_ATTRIBUTES_H

#include <godot_cpp/classes/camera_attributes.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCameraAttributes godot::CameraAttributes

#include "../core/resource.h"

using namespace godot;

namespace lucidfx::spatial {
    void bindCameraAttributes(sol::state_view& lua);

    class CameraAttributes : public lucidfx::core::Resource {
    private:
        GodotCameraAttributes* cameraAttributes = nullptr;
    public:
        CameraAttributes() {
            setCameraAttributes(memnew(GodotCameraAttributes));
        }

        CameraAttributes(GodotCameraAttributes* ca) {
            setCameraAttributes(ca);
        }

        GodotCameraAttributes* getCameraAttributes() {
            return cameraAttributes;
        }

        void setCameraAttributes(GodotCameraAttributes* ca) {
            cameraAttributes = ca;
            cameraAttributes->reference();
            setResource(cameraAttributes);
        }

        bool getAutoExposureEnabled() {
            return cameraAttributes->is_auto_exposure_enabled();
        }

        void setAutoExposureEnabled(bool enabled) {
            cameraAttributes->set_auto_exposure_enabled(enabled);
        }

        float getAutoExposureScale() {
            return cameraAttributes->get_auto_exposure_scale();
        }

        void setAutoExposureScale(float scale) {
            cameraAttributes->set_auto_exposure_scale(scale);
        }

        float getAutoExposureSpeed() {
            return cameraAttributes->get_auto_exposure_speed();
        }

        void setAutoExposureSpeed(float speed) {
            cameraAttributes->set_auto_exposure_speed(speed);
        }

        float getExposureMultiplier() {
            return cameraAttributes->get_exposure_multiplier();
        }

        void setExposureMultiplier(float multiplier) {
            cameraAttributes->set_exposure_multiplier(multiplier);
        }

        float getExposureSensitivity() {
            return cameraAttributes->get_exposure_sensitivity();
        }

        void setExposureSensitivity(float sensitivity) {
            cameraAttributes->set_exposure_sensitivity(sensitivity);
        }
    };
}

#endif // CAMERA_ATTRIBUTES_H