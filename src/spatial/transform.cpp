#include "transform.h"

#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;
using namespace newhaven_core;
namespace newhaven_spatial {

    void SpatialTransform::_updateLocalTransform() const {
        data.localTransform.basis.set_euler_scale(data.eulerRotation, data.scale, data.eulerRotationOrder);
        _clear_dirty_bits(DIRTY_LOCAL_TRANSFORM);
    }

    void SpatialTransform::_updateRotationAndScale() const {
        data.scale = data.localTransform.basis.get_scale();
        data.eulerRotation = data.localTransform.basis.get_euler_normalized(data.eulerRotationOrder);
        _clear_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE);
    }

    void SpatialTransform::onNotification(int p_what) {
        switch (p_what)
        {
            case NOTIFICATION_ENTER_TREE: {
                
                Entity* p = entity->parent;
                if (p) {
                    data.parentTransform = &(p->getComponent("SpatialTransform")->cast<SpatialTransform>());
                }

                if (data.parentTransform) {
                    data.C = data.parentTransform->data.children.push_back(this);
                } else {
                    data.C = nullptr;
                }

                if (data.topLevel && !Engine::get_singleton()->is_editor_hint()) {
                    if (data.parentTransform) {
                        if (!data.topLevel) {
                            data.localTransform = data.parentTransform->getGlobalTransform() * getTransform();
                        } else {
                            data.localTransform = getTransform();
                        }
                        _replace_dirty_mask(DIRTY_EULER_ROTATION_AND_SCALE);
                    }
                }

                _set_dirty_bits(DIRTY_GLOBAL_TRANSFORM);
                _notify_dirty();

                notification(NOTIFICATION_ENTER_WORLD);
                _update_visibility_parent(true);
            } break;
            case NOTIFICATION_EXIT_TREE: {

                notification(NOTIFICATION_EXIT_WORLD, true);
                if (xform_change.in_list()) {
                    scene->xform_change_list.remove(&xform_change);
                }
                if (data.C) {
                    data.parentTransform->data.children.erase(data.C);
                }
                data.parentTransform = nullptr;
                data.C = nullptr;
                _update_visibility_parent(true);
            } break;
            case NOTIFICATION_ENTER_WORLD: {

                data.insideWorld = true;
                data.viewport = scene->viewport; 
            } break;

            case NOTIFICATION_EXIT_WORLD: {
                data.viewport = nullptr;
                data.insideWorld = false;
            } break;

            case NOTIFICATION_TRANSFORM_CHANGED: {
                //
            } break;
        }
    }

    void SpatialTransform::setBasis(const Basis& p_basis) const {
        setTransform(Transform3D(p_basis, data.localTransform.origin));
    }

    void SpatialTransform::setQuaternion(const Quaternion& p_quat) const {
        if (_test_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE)) {
            data.scale = data.localTransform.basis.get_scale();
            _clear_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE);
        }
        data.localTransform.basis = Basis(p_quat, data.scale);
        data.eulerRotation = data.localTransform.basis.get_euler_normalized(data.eulerRotationOrder);

        _replace_dirty_mask(DIRTY_NONE);

        _propagate_transform_changed(this);
        if (data.notifyLocalTransform) {
            notification(NOTIFICATION_LOCAL_TRANSFORM_CHANGED);
        }
    }

    Vector3 SpatialTransform::getGlobalPosition() const {
        return getGlobalTransform().origin;
    }

    Basis SpatialTransform::getGlobalBasis() const {
        return getGlobalTransform().basis;
    }

    void SpatialTransform::setGlobalPosition(const Vector3& p_position) {
        Transform3D transform = getGlobalTransform();
        transform.set_origin(p_position);
        setGlobalTransform(transform);
    }

    void SpatialTransform::setGlobalBasis(const Basis& p_basis) {
        Transform3D transform = getGlobalTransform();
        transform.set_basis(p_basis);
        setGlobalTransform(transform);
    }

    Vector3 SpatialTransform::getGlobalRotation() const {
        return getGlobalTransform().get_basis().get_euler();
    }

    Vector3 SpatialTransform::getGlobalRotationDegrees() const {
        Vector3 radians = getGlobalRotation();
        return Vector3(Math::rad_to_deg(radians.x), Math::rad_to_deg(radians.y), Math::rad_to_deg(radians.z));
    }

    void SpatialTransform::setGlobalRotation(const Vector3& p_rotation) {
        Transform3D transform = getGlobalTransform();
        transform.basis = Basis::from_euler(p_rotation) * Basis::from_scale(transform.basis.get_scale());
        setGlobalTransform(transform);
    }

    void SpatialTransform::setGlobalRotationDegrees(const Vector3& p_rotation) {
        Vector3 radians = Vector3(Math::deg_to_rad(p_rotation.x), Math::deg_to_rad(p_rotation.y), Math::deg_to_rad(p_rotation.z));
        setGlobalRotation(radians);
    }

    void SpatialTransform::setTransform(const Transform3D& p_transform) const {
        data.localTransform = p_transform;
        _replace_dirty_mask(DIRTY_EULER_ROTATION_AND_SCALE);

        _propagate_transform_changed(this);
        if (data.notifyLocalTransform) {
            notification(NOTIFICATION_LOCAL_TRANSFORM_CHANGED);
        }
    }

    Basis SpatialTransform::getBasis() const {
        return getTransform().basis;
    }

    Quaternion SpatialTransform::getQuaternion() const {
        return getTransform().basis.get_rotation_quaternion();
    }

    void SpatialTransform::setGlobalTransform(const Transform3D& p_transform) const {
        Transform3D xform = (data.parentTransform && !data.topLevel) 
            ? data.parentTransform->getGlobalTransform().affine_inverse() * p_transform 
            : p_transform;

        setTransform(xform);
    }

    Transform3D SpatialTransform::getTransform() const {
        if (_test_dirty_bits(DIRTY_LOCAL_TRANSFORM)) {
            _updateLocalTransform();
        }

        return data.localTransform;
    }

    Transform3D SpatialTransform::getGlobalTransform() const {
        uint32_t dirty = _read_dirty_mask();
        if (dirty & DIRTY_GLOBAL_TRANSFORM) {
            if (dirty &  DIRTY_LOCAL_TRANSFORM) {
                _updateLocalTransform();
            }

            Transform3D newGlobal;
            if (data.parentTransform && !data.topLevel) {
                newGlobal = data.parentTransform->getGlobalTransform() * data.localTransform;
            } else {
                newGlobal = data.localTransform;
            }
            
            if (data.disableScale) {
                newGlobal.basis.orthonormalize();
            }

            data.globalTransform = newGlobal;
            _clear_dirty_bits(DIRTY_GLOBAL_TRANSFORM);
        }

        return data.globalTransform;
    }

    SpatialTransform* SpatialTransform::getParentTransform() const {
        if (data.topLevel) {
            return nullptr;
        }

        return &(entity->parent->getComponent("SpatialTransform")->cast<SpatialTransform>());
    }

    Transform3D SpatialTransform::getRelativeTransform(const Entity* p_parent) const {
        if (p_parent == this->entity) {
            return Transform3D();
        } 

        if (p_parent == data.parentTransform->entity) {
            return getTransform();
        } else {
            return data.parentTransform->getRelativeTransform(p_parent) * getTransform();
        }
    }

    void SpatialTransform::setPosition(const Vector3& p_position) {
        data.localTransform.origin = p_position;
        _propagate_transform_changed(this);
        if (data.notifyLocalTransform) {
            notification(NOTIFICATION_LOCAL_TRANSFORM_CHANGED);
        }
    }

    void SpatialTransform::setRotationOrder(EulerOrder p_order) {
        if (data.eulerRotationOrder == p_order) {
            return;
        }

        bool transformChnaged = false;

        uint32_t dirty = _read_dirty_mask();
        if ((dirty & DIRTY_EULER_ROTATION_AND_SCALE)) {
            _updateRotationAndScale();
        } else if ((dirty & DIRTY_LOCAL_TRANSFORM)) {
            data.eulerRotation = Basis::from_euler(data.eulerRotation, data.eulerRotationOrder).get_euler_normalized(p_order);
            transformChnaged = true;
        } else {
            _set_dirty_bits(DIRTY_LOCAL_TRANSFORM);
            transformChnaged = true;
        }

        data.eulerRotationOrder = p_order;

        if (transformChnaged) {
            _propagate_transform_changed(this);
            if (data.notifyLocalTransform) {
                notification(NOTIFICATION_LOCAL_TRANSFORM_CHANGED);
            }
        }
    }

    EulerOrder SpatialTransform::getRotationOrder() const {
        return data.eulerRotationOrder;
    }

    void SpatialTransform::setRotation(const Vector3& p_rotation) {
        
    }
}

