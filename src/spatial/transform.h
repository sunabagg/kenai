#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <vector>
#include <sol/sol.hpp>
#include <godot_cpp/templates/safe_refcount.hpp>
#include <godot_cpp/templates/self_list.hpp>

#include "../core/scene_system.h"

using namespace godot;
using namespace newhaven_core;

namespace newhaven_spatial
{
    void bindSpatialTransform( sol::state& lua );

    template<typename T>
    T bit_and(SafeNumeric<T>& sn, T p_value) {
        std::atomic<T> &value = sn.value;
		return value.fetch_and(p_value, std::memory_order_acq_rel);
	}

    class SpatialTransform : public Component
    {
    private:

        enum TransformDirty {
		    DIRTY_NONE = 0,
		    DIRTY_EULER_ROTATION_AND_SCALE = 1,
		    DIRTY_LOCAL_TRANSFORM = 2,
		    DIRTY_GLOBAL_TRANSFORM = 4
	    };

        mutable SelfList<Entity> xform_change;

        struct Data
        {
            mutable Transform3D globalTransform;
            mutable Transform3D localTransform;
            mutable EulerOrder eulerRotationOrder = EulerOrder::EULER_ORDER_YXZ;
            mutable Vector3 eulerRotation;
            mutable Vector3 scale = Vector3( 1, 1, 1 );

            mutable MTNumeric<uint32_t> dirty;

            Viewport *viewport = nullptr;

            bool topLevel = false;
            bool insideWorld = false;

            RID visibilityParent;

            SpatialTransform *parentTransform = nullptr;
            List<SpatialTransform *> children;
            List<SpatialTransform *>::Element *C = nullptr;

            bool ignoreNotification = false;
            bool notifyLocalTransform = false;
            bool notifyTransform = false;

            bool visible = true;
            bool disableScale = false;
        } data;

        _FORCE_INLINE_ uint32_t _read_dirty_mask() const { return  data.dirty.mt.get(); }
	    _FORCE_INLINE_ bool _test_dirty_bits(uint32_t p_bits) const { return bit_and(data.dirty.mt, p_bits); }
	    void _replace_dirty_mask(uint32_t p_mask) const;
	    void _set_dirty_bits(uint32_t p_bits) const;
	    void _clear_dirty_bits(uint32_t p_bits) const;

        void _notify_dirty();
	    void _propagate_transform_changed(const SpatialTransform *p_origin) const;

        void _propagate_visibility_changed();

	    void _propagate_visibility_parent();
	    void _update_visibility_parent(bool p_update_root);
	    void _propagate_transform_changed_deferred();

    protected:
        _FORCE_INLINE_ void  setIgnoreTransformNotification( bool ignore ) { data.ignoreNotification = ignore; }

        _FORCE_INLINE_ void _updateLocalTransform() const;
        _FORCE_INLINE_ void _updateRotationAndScale() const;

    public:
        void onNotification( int p_what ) override;

        enum
        {
            NOTIFICATION_TRANSFORM_CHANGED = 2000,
            NOTIFICATION_ENTER_WORLD = 41,
            NOTIFICATION_EXIT_WORLD = 42,
            NOTIFICATION_VISIBILITY_CHANGED = 43,
            NOTIFICATION_LOCAL_TRANSFORM_CHANGED = 44,
        };

        SpatialTransform *getParentTransform() const;

        Ref<World3D> getWorld() const;

        void setPosition(const Vector3 &pPosition);

        void setRotationOrder(EulerOrder pOrder);
        void setRotation(const Vector3 &pEulerRad);
        void setRotationDegrees(const Vector3 &pEulerDeg);
        void setScale(const Vector3 &pScale);

        void setGlobalPosition(const Vector3 &pPosition);
        void setGlobalBasis(const Basis &pBasis);
        void setGlobalRotation(const Vector3 &pEulerRad);
        void setGlobalRotationDegrees(const Vector3 &pEulerDeg);

        Vector3 getPosition() const;
        Transform3D getTransform() const;
        EulerOrder getRotationOrder() const;
        Vector3 getRotation() const;
        Vector3 getRotationDegrees() const;
        Quaternion getQuaternion() const;
        Vector3 getScale() const;
        Basis getBasis() const;

        Transform3D getGlobalTransform() const;
        Vector3 getGlobalPosition() const;
        Basis getGlobalBasis() const;
        Vector3 getGlobalRotation() const;
        Vector3 getGlobalRotationDegrees() const;

        void setTransform(const Transform3D &pTransform) const;
        void setBasis(const Basis &p_basis) const;
        void setQuaternion(const Quaternion &pQuaternion) const;
        void setGlobalTransform(const Transform3D &pTransform) const;

        void setAsTopLevel(bool pEnabled);
        void setAsTopLevelKeepLocal(bool pEnabled);
        bool isScaleDisabled() const;

        _FORCE_INLINE_ bool isInsideWorld() const { return data.insideWorld; }

        Transform3D getRelativeTransform(const Entity *pParent) const;

        void rotate(const Vector3 &pAxis, real_t pAngle);
        void rotateX(real_t pAngle);
        void rotateY(real_t pAngle);
        void rotateZ(real_t pAngle);
        void translate(const Vector3 &pOffset);
        void scale(const Vector3 &pRatio);

        void rotateObjectLocal(const Vector3 &pAxis, real_t pAngle);
        void scaleObjectLocal(const Vector3 &pScale);
        void translateObjectLocal(const Vector3 &pOffset);

        void globalRotate(const Vector3 &pAxis, real_t pAngle);
        void globalScale(const Vector3 &pScale);
        void globalTranslate(const Vector3 &pOffset);

        void lookAt(const Vector3 &pTarget, const Vector3 &pUp = Vector3(0, 1, 0), bool pUseModelFront = false);
        void lookAtFromPosition(const Vector3 &pPos, const Vector3 &pTarget, const Vector3 &pUp = Vector3(0, 1, 0), bool pUseModelFront = false);

        Vector3 toLocal(Vector3 pGlobal) const;
        Vector3 toGlobal(Vector3 pLocal) const;

        void setNotifyTransform(bool pEnabled);
        bool isTransformNotificationEnabled() const;

        void setNotifyLocalTransform(bool pEnabled);
        bool isLocalTransformNotificationEnabled() const;

        void orthonormalize();
        void setIdentity();

        void setVisible(bool pVisible);
        void show();
        void hide();
        bool isVisible() const;
        bool isVisibleInScene() const;

        void forceUpdateTransform();

        void setVisibilityParent(const std::string &pPath);

        SpatialTransform();
    };
}

#endif // TRANSFORM_H