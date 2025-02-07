#include "transform.h"

#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace newhaven_core;
using namespace godot;

namespace newhaven_spatial {
    void bindSpatialTransform( sol::state &lua )
    {
    }

    void SpatialTransform::_notify_dirty() {
        if (data.notifyTransform && !data.ignoreNotification && !xform_change.in_list()) {
		    scene->xform_change_list.add(&xform_change);
	    }
    }

    void SpatialTransform::_propagate_transform_changed(const SpatialTransform *p_origin) {
        if (!scene && !entity->parent) return;

        for (SpatialTransform* &E : data.children) {
            if (E->data.topLevel) {
                continue;
            }
            E->_propagate_transform_changed(p_origin);
            if (data.notifyTransform && !data.ignoreNotification && !xform_change.in_list()) {
                scene->xform_change_list.add(&xform_change);
            }
        }
        _set_dirty_bits(DIRTY_GLOBAL_TRANSFORM);
    }

    void SpatialTransform::_propagate_transform_changed_deferred() {
        if ((scene && entity->parent) && !xform_change.in_list()) {
            scene->xform_change_list.add(&xform_change);
        }
    }

    void SpatialTransform::_updateLocalTransform() const {
        data.localTransform.basis.set_euler_scale(data.eulerRotation, data.scale, data.eulerRotationOrder);
        _clear_dirty_bits(DIRTY_LOCAL_TRANSFORM);
    }

    void SpatialTransform::_updateRotationAndScale() const {
        data.scale = data.localTransform.basis.get_scale();
        data.eulerRotation = data.localTransform.basis.get_euler_normalized(data.eulerRotationOrder);
        _clear_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE);
    }

    void SpatialTransform::onEnterTree() {
        Entity* p = entity->parent;
        if (p) {
        data.parentTransform = static_cast<SpatialTransform*>(
            p->getComponent( "SpatialTransform" ) );
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

        onEnterWorld();
        _update_visibility_parent(true);
    }

    void SpatialTransform::onExitTree() {
        onExitWorld();
        if (xform_change.in_list()) {
            scene->xform_change_list.remove(&xform_change);
        }
        if (data.C) {
            data.parentTransform->data.children.erase(data.C);
        }
        data.parentTransform = nullptr;
        data.C = nullptr;
        _update_visibility_parent(true);
    }

    void SpatialTransform::onEnterWorld() {
        data.insideWorld = true;
        data.viewport = scene->viewport; 
    }

    void SpatialTransform::onExitWorld() {
        data.viewport = nullptr;
        data.insideWorld = false;
    }

    void SpatialTransform::onNotification(int p_what) {
        switch (p_what)
        {
            case NOTIFICATION_ENTER_TREE: {
            } break;
            case NOTIFICATION_EXIT_TREE: {

                
            } break;
            case NOTIFICATION_ENTER_WORLD: {
            } break;

            case NOTIFICATION_EXIT_WORLD: {
                
            } break;

            case NOTIFICATION_TRANSFORM_CHANGED: {
                _updateLocalTransform();
            } break;

            case NOTIFICATION_LOCAL_TRANSFORM_CHANGED: {
                setGlobalTransform(getTransform());
            }break;
        }
    }
    void SpatialTransform::onLocalTransformChanged() {
        setGlobalTransform(getTransform());
    }

    void SpatialTransform::setGlobalScale(const Vector3& p_scale) {
        Transform3D t = getGlobalTransform();
        t.basis.scale(p_scale);
        setGlobalTransform(t);
    }

    void SpatialTransform::setBasis(const Basis& p_basis) {
        setTransform(Transform3D(p_basis, data.localTransform.origin));
    }

    void SpatialTransform::setQuaternion(const Quaternion& p_quat) {
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

    void SpatialTransform::setTransform(const Transform3D& p_transform) {
        data.localTransform = p_transform;
        _replace_dirty_mask(DIRTY_EULER_ROTATION_AND_SCALE);

        _propagate_transform_changed(this);
        if (data.notifyLocalTransform) {
            onLocalTransformChanged();
        }
    }

    Basis SpatialTransform::getBasis() const {
        return getTransform().basis;
    }

    Quaternion SpatialTransform::getQuaternion() const {
        return getTransform().basis.get_rotation_quaternion();
    }

    void SpatialTransform::setGlobalTransform(const Transform3D& p_transform) {
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

        return static_cast<SpatialTransform*>(
            entity->parent->getComponent( "SpatialTransform" ) );
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
        if (_test_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE)) {
            data.scale = data.localTransform.basis.get_scale();
            _clear_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE);
        }

        data.eulerRotation = p_rotation;
        _replace_dirty_mask(DIRTY_LOCAL_TRANSFORM);
        _propagate_transform_changed(this);
        if (data.notifyLocalTransform) {
            notification(NOTIFICATION_LOCAL_TRANSFORM_CHANGED);
        }
    }

    void SpatialTransform::setRotationDegrees(const Vector3& p_rotation) {
        Vector3 radians = Vector3(Math::deg_to_rad(p_rotation.x), Math::deg_to_rad(p_rotation.y), Math::deg_to_rad(p_rotation.z));
        setRotation(radians);
    }

    void SpatialTransform::setScale(const Vector3& p_scale) {
        if (_test_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE)) {
            data.eulerRotation = data.localTransform.basis.get_euler_normalized(data.eulerRotationOrder);
            _clear_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE);
        }

        data.scale = p_scale;
        _replace_dirty_mask(DIRTY_LOCAL_TRANSFORM);
        _propagate_transform_changed(this);
        if (data.notifyLocalTransform) {
            notification(NOTIFICATION_LOCAL_TRANSFORM_CHANGED);
        }
    }

    Vector3 SpatialTransform::getPosition() const {
        return data.localTransform.origin;
    }

    Vector3 SpatialTransform::getRotation() const {
        if (_test_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE)) {
            _updateRotationAndScale();
        }

        return data.eulerRotation;
    }

    Vector3 SpatialTransform::getRotationDegrees() const {
        Vector3 radians = getRotation();
        return Vector3(Math::rad_to_deg(radians.x), Math::rad_to_deg(radians.y), Math::rad_to_deg(radians.z));
    }

    Vector3 SpatialTransform::getScale() const {
        if (_test_dirty_bits(DIRTY_EULER_ROTATION_AND_SCALE)) {
            _updateRotationAndScale();
        }

        return data.scale;
    }

    Vector3 SpatialTransform::getGlobalScale() const {
        return getGlobalTransform().basis.get_scale();
    }

    void SpatialTransform::_replace_dirty_mask(uint32_t p_mask) const {
        data.dirty.mt.set(p_mask);
    }

    void SpatialTransform::_set_dirty_bits(const uint32_t p_mask) {
         data.dirty.mt.bit_or( p_mask );
    }

    void SpatialTransform::_clear_dirty_bits(uint32_t p_mask) const {
        data.dirty.mt.bit_and(  ~p_mask );
    }

    void SpatialTransform::setDisableScale(bool p_disable) {
        if (data.disableScale == p_disable) {
            return;
        }

        data.disableScale = p_disable;
    }

    bool SpatialTransform::isScaleDisabled() const {
        return data.disableScale;    
    }

    void SpatialTransform::setAsTopLevel(bool p_enable) {
        if (data.topLevel == p_enable) {
            return;
        }
        if (scene && entity->parent) {
            if (p_enable) {
                setTransform(getGlobalTransform());
            } else if (data.parentTransform) {
                setTransform(data.parentTransform->getGlobalTransform().affine_inverse() * getGlobalTransform());
            }
        }
        data.topLevel = p_enable;
    }

    void SpatialTransform::setAsTopLevelKeepLocal(bool p_enable) {
        if (data.topLevel == p_enable) {
            return;
        }
        data.topLevel = p_enable;
        _propagate_transform_changed(this);
    }

    bool SpatialTransform::isSetAsTopLevel() const {
        return data.topLevel;
    }

    Ref<World3D> SpatialTransform::getWorld() const {
        if (scene) {
            return scene->viewport->find_world_3d();
        }
        return nullptr;
    }

    void SpatialTransform::_propagate_visibility_changed() {
        notification(NOTIFICATION_VISIBILITY_CHANGED);

        for (SpatialTransform* child : data.children) {
            if (!child || !child->data.visible) {
                continue;
            }
            child->_propagate_visibility_changed();
        }
    }

    void SpatialTransform::show() {
        setVisible(true);
    }

    void SpatialTransform::hide() {
        setVisible(false);
    }

    void SpatialTransform::setVisible(bool p_visible) {
        if (data.visible == p_visible) {
            return;
        }

        data.visible = p_visible;

        if (!scene && !entity->parent) {
            return;
        }
        _propagate_visibility_changed();
    }

    bool SpatialTransform::isVisible() const {
        return data.visible;
    }

    bool SpatialTransform::isVisibleInTree() const {
        if (!scene) {
            return false;
        }

        const SpatialTransform* s = this;
        while (s) {
            if (!s->data.visible) {
                return false;
            }
            s = s->data.parentTransform;
        }
        return true;
    }

    void SpatialTransform::rotateObjectLocal(const Vector3& p_axis, real_t p_angle) {
        Transform3D t = getTransform();
        t.basis.rotate_local(p_axis, p_angle);
        setTransform(t);
    }

    void SpatialTransform::rotate(const Vector3& p_axis, real_t p_angle) {
        Transform3D t = getTransform();
        t.basis.rotate(p_axis, p_angle);
        setTransform(t);
    }

    void SpatialTransform::rotateX(real_t p_angle) {
        Transform3D t = getTransform();
        t.basis.rotate(Vector3(1, 0, 0), p_angle);
        setTransform(t);
    }

    void SpatialTransform::rotateY(real_t p_angle) {
        Transform3D t = getTransform();
        t.basis.rotate(Vector3(0, 1, 0), p_angle);
        setTransform(t);
    }

    void SpatialTransform::rotateZ(real_t p_angle) {
        Transform3D t = getTransform();
        t.basis.rotate(Vector3(0, 0, 1), p_angle);
        setTransform(t);
    }

    void SpatialTransform::translate(const Vector3& p_offset) {
        Transform3D t = getTransform();
        t.translate_local(p_offset);
        setTransform(t);
    }

    void SpatialTransform::translateObjectLocal(const Vector3& p_offset) {
        Transform3D t = getTransform();

        Transform3D s;
        s.translate_local(p_offset);
        setTransform(t * s);
    }

    void SpatialTransform::scale(const Vector3& p_scale) {
        Transform3D t = getTransform();
        t.basis.scale(p_scale);
        setTransform(t);
    }

    void SpatialTransform::scaleObjectLocal(const Vector3& p_scale) {
        Transform3D t = getTransform();
        t.basis.scale_local(p_scale);
        setTransform(t);
    }

    void SpatialTransform::globalRotate(const Vector3& p_axis, real_t p_angle) {
        Transform3D t = getGlobalTransform();
        t.basis.rotate(p_axis, p_angle);
        setGlobalTransform(t);
    }

    void SpatialTransform::globalScale(const Vector3& p_scale) {
        Transform3D t = getGlobalTransform();
        t.basis.scale(p_scale);
        setGlobalTransform(t);
    }

    void SpatialTransform::globalTranslate(const Vector3& p_offset) {
        Transform3D t = getGlobalTransform();
        t.origin += p_offset;
        setGlobalTransform(t);
    }

    void SpatialTransform::orthonormalize() {
        Transform3D t = getTransform();
        t.orthogonalize();
        setTransform(t);
    }

    void SpatialTransform::setIdentity() {
        setTransform(Transform3D());
    }

    void SpatialTransform::lookAt(const Vector3& p_target, const Vector3& p_up, bool p_use_model_front) {
        Vector3 origin = getGlobalTransform().origin;
        lookAtFromPosition(origin, p_target, p_up, p_use_model_front);
    }

    void SpatialTransform::lookAtFromPosition(const Vector3& p_position, const Vector3& p_target, const Vector3& p_up, bool p_use_model_front) {
        Vector3 forward = p_target - p_position;
        Basis lookat_basis = Basis::looking_at(forward, p_up);
        Vector3 originalScale = getScale();
        setGlobalTransform(Transform3D(lookat_basis, p_position));
        setScale(originalScale);
    }

    Vector3 SpatialTransform::toLocal(Vector3 p_vector) const {
        return getGlobalTransform().affine_inverse().xform(p_vector);
    }

    Vector3 SpatialTransform::toGlobal(Vector3 p_vector) const {
        return getGlobalTransform().xform(p_vector);
    }

    void SpatialTransform::setNotifyTransform(bool p_notify) {
        data.notifyTransform = p_notify;
    }

    void SpatialTransform::setNotifyLocalTransform(bool p_notify) {
        data.notifyLocalTransform = p_notify;
    }

    bool SpatialTransform::isLocalTransformNotificationEnabled() const {
        return data.notifyLocalTransform;
    }

    void SpatialTransform::forceUpdateTransform() {
        if (!xform_change.in_list()) {
            return;
        }
        scene->xform_change_list.remove(&xform_change);
    }

    void SpatialTransform::_update_visibility_parent(bool p_update_root) {
        RID new_parent;

        if (!visibilityParentPath.empty()) {
            if (!p_update_root) {
                return;
            }
            //Entity* parent = entity->find(visibilityParentPath);
            //GeometryInstance3D *gi = Object::cast_to<GeometryInstance3D>(parent);
            //new_parent = gi ? gi->get_instance() : RID();
        } else if (data.parentTransform) {
            new_parent = data.parentTransform->data.visibilityParent;
        }

        if (new_parent == data.visibilityParent) {
            return;
        }

        //VisualInstance3D *vi = Object::cast_to<VisualInstance3D>(this);
        //if (vi) {
		//    RS::get_singleton()->instance_set_visibility_parent(vi->get_instance(), data.visibility_parent);
	    //}

        for (SpatialTransform *child : data.children) {
            child->_update_visibility_parent(false);
        }
    }

    void SpatialTransform::setVisibilityParent(const std::string& p_path) {
        visibilityParentPath = p_path;
        if (scene && entity->parent) {
            _update_visibility_parent(true);
        }
    }

    std::string SpatialTransform::getVisibilityParent() const {
        return visibilityParentPath;
    }

    bool SpatialTransform::isTransformNotificationEnabled() const {
        return data.notifyTransform;
    }

    SpatialTransform::SpatialTransform() : xform_change(this->entity) {}

    void SpatialTransform::onFree() {
        
    }
}

