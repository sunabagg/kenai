#ifndef CAMERA_ATTRIBUTES_PRACTICAL_H
#define CAMERA_ATTRIBUTES_PRACTICAL_H

#include <godot_cpp/classes/camera_attributes_practical.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCameraAttributesPractical godot::CameraAttributesPractical

#include "camera_attributes.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindCameraAttributesPractical(sol::state_view& lua);

    class CameraAttributesPractical : public CameraAttributes {
    private:
        GodotCameraAttributesPractical* cameraAttributesPractical = nullptr;
    public:
        CameraAttributesPractical() {
            setCameraAttributesPractical(memnew(GodotCameraAttributesPractical));
        }

        CameraAttributesPractical(GodotCameraAttributesPractical* cap) {
            setCameraAttributesPractical(cap);
        }

        GodotCameraAttributesPractical* getCameraAttributesPractical() {
            return cameraAttributesPractical;
        }

        void setCameraAttributesPractical(GodotCameraAttributesPractical* cap) {
            cameraAttributesPractical = cap;
            cameraAttributesPractical->reference();
            setResource(cameraAttributesPractical);
        }

        float getAutoExposureMaxSensitivity() {
            return cameraAttributesPractical->get_auto_exposure_max_sensitivity();
        }

        void setAutoExposureMaxSensitivity(float maxSensitivity) {
            cameraAttributesPractical->set_auto_exposure_max_sensitivity(maxSensitivity);
        }

        float getAutoExposureMinSensitivity() {
            return cameraAttributesPractical->get_auto_exposure_min_sensitivity();
        }

        void setAutoExposureMinSensitivity(float minSensitivity) {
            cameraAttributesPractical->set_auto_exposure_min_sensitivity(minSensitivity);
        }

        float getDofBlurAmount() {
            return cameraAttributesPractical->get_dof_blur_amount();
        }

        void setDofBlurAmount(float blurAmount) {
            cameraAttributesPractical->set_dof_blur_amount(blurAmount);
        }

        float getDofBlurFarDistance() {
            return cameraAttributesPractical->get_dof_blur_far_distance();
        }

        void setDofBlurFarDistance(float farDistance) {
            cameraAttributesPractical->set_dof_blur_far_distance(farDistance);
        }

        bool getDofBlurFarEnabled() {
            return cameraAttributesPractical->is_dof_blur_far_enabled();
        }

        void setDofBlurFarEnabled(bool enabled) {
            cameraAttributesPractical->set_dof_blur_far_enabled(enabled);
        }

        float getDofBlurFarTransition() {
            return cameraAttributesPractical->get_dof_blur_far_transition();
        }

        void setDofBlurFarTransition(float farTransition) {
            cameraAttributesPractical->set_dof_blur_far_transition(farTransition);
        }

        float getDofBlurNearDistance() {
            return cameraAttributesPractical->get_dof_blur_near_distance();
        }

        void setDofBlurNearDistance(float nearDistance) {
            cameraAttributesPractical->set_dof_blur_near_distance(nearDistance);
        }

        bool getDofBlurNearEnabled() {
            return cameraAttributesPractical->is_dof_blur_near_enabled();
        }

        void setDofBlurNearEnabled(bool enabled) {
            cameraAttributesPractical->set_dof_blur_near_enabled(enabled);
        }

        float getDofBlurNearTransition() {
            return cameraAttributesPractical->get_dof_blur_near_transition();
        }

        void setDofBlurNearTransition(float nearTransition) {
            cameraAttributesPractical->set_dof_blur_near_transition(nearTransition);
        }
    };
}

#endif // CAMERA_ATTRIBUTES_PRACTICAL_H