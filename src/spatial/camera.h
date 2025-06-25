#ifndef CAMERA_H
#define CAMERA_H

#include <godot_cpp/classes/camera3d.hpp>

#include "../core/scene_system.h"
#include "transform.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindCamera(sol::state& lua);

    class Camera : public Component {
    protected:
        Camera3D* node;
    public:
        int getCullMask() {
            return node->get_cull_mask();
        }
        void setCullMask(int mask) {
            node->set_cull_mask(mask);
        }

        bool getCurrent() {
            return node->is_current();   
        }
        void setCurrent(bool current) {
            node->set_current(current);
        }

        int getDopplerTracking() {
            return node->get_doppler_tracking();
        }
        void setDopplerTracking(int tracking) {
            node->set_doppler_tracking(static_cast<Camera3D::DopplerTracking>(tracking));
        }

        float getFar() {
            return node->get_far();
        }
        void setFar(float far) {
            node->set_far(far);
        }

        float getFov() {
            return node->get_fov();
        }
        void setFov(float fov) {
            node->set_fov(fov);
        }

        Vector2 getFrustumOffset() {
            return node->get_frustum_offset();
        }
        void setFrustumOffset(Vector2 offset) {
            node->set_frustum_offset(offset);
        }

        float getHOffset() {
            return node->get_h_offset();
        }
        void setHOffset(float offset) {
            node->set_h_offset(offset);
        }

        float getKeepAspect() {
            return node->get_keep_aspect_mode();
        }
        void setKeepAspect(float aspect) {
            node->set_keep_aspect_mode(static_cast<Camera3D::KeepAspect>(aspect));
        }

        float getNear() {
            return node->get_near();
        }
        void setNear(float near) {
            node->set_near(near);
        }

        int getProjection() {
            return node->get_projection();
        }
        void setProjection(int projection) {
            node->set_projection(static_cast<Camera3D::ProjectionType>(projection));
        }

        float getSize() {
            return node->get_size();
        }
        void setSize(float size) {
            node->set_size(size);
        }

        float getVOffset() {
            return node->get_v_offset();
        }
        void setVOffset(float offset) {
            node->set_v_offset(offset);
        }

        void clearCurrent() {
            node->clear_current();
        }

        bool getCullMaskValue(int index) {
            return node->get_cull_mask_value(index);
        }

        std::vector<Plane> getFrustum() {
            auto gdFrustum = node->get_frustum();
            std::vector<Plane> frustum;
            for (int i = 0; i < 6; i++) {
                frustum.push_back(gdFrustum[i]);
            }
            return frustum;
        }

        bool isPositionBehind(Vector3 position) {
            return node->is_position_behind(position);
        }

        bool isPositionInFrustum(Vector3 position) {
            return node->is_position_in_frustum(position);
        }

        void makeCurrent() {
            node->make_current();
        }

        Vector3 projectLocalRayNormal(Vector2 screenPoint) {
            return node->project_local_ray_normal(screenPoint);
        }

        Vector3 projectPosition(Vector2 screenPoint, float zDepth) {
            return node->project_position(screenPoint, zDepth);
        }

        Vector3 projectRayNormal(Vector2 screenPoint) {
            return node->project_ray_normal(screenPoint);
        }

        Vector3 projectRayOrigin(Vector2 screenPoint) {
            return node->project_ray_origin(screenPoint);
        }

        void setCullMaskValue(int index, bool value) {
            node->set_cull_mask_value(index, value);
        }

        void setFrustum(float size, Vector2 offset, float zNear, float zFar) {
            node->set_frustum(size, offset, zNear, zFar);
        }

        void setOrthogonal(float size, float zNear, float zFar) {
            node->set_orthogonal(size, zNear, zFar);
        }

        void setPerspective(float fov, float zNear, float zFar) {
            node->set_perspective(fov, zNear, zFar);
        }

        Vector2 unprojectPosition(Vector3 position) {
            return node->unproject_position(position);
        }

        void onInit() override {
            node = memnew(Camera3D);
            node->set_name("Camera");
            SpatialTransform* transform = entity->getComponentByT<SpatialTransform>();
            if (transform) {
                transform->getNode()->add_child(node);
            }
        }

        void onFree() override {
            Component::onFree();
            if (node != nullptr) {
                node->queue_free();
            }
        }
    };
}

#endif