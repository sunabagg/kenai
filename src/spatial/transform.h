#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <vector>
#include <sol/sol.hpp>

#include "../core/scene_system.h"

using namespace godot;
using namespace newhaven_core;

namespace newhaven_spatial
{
    void bindSpatialTransform( sol::state& lua );

    class SpatialTransform : public Component
    {
    private:
        struct Data
        {
            mutable Transform3D globalTransform;
            mutable Transform3D localTransform;
            mutable EulerOrder eulerRotationOrder = EulerOrder::YXZ;
            mutable Vector3 eulerRotation;
            mutable Vector3 scale = Vector3( 1, 1, 1 );

            Viewport *viewport = nullptr;

            bool topLevel = false;
            bool insideWorld = false;

            RID visibilityParent;

            SpatialTransform *parentTransform = nullptr;
            std::vector<SpatialTransform *> children;

            bool ignoreNotification = false;
            bool notifyLocalTransform = false;
            bool notifyTransform = false;

            bool visible = true;
            bool disableScale = false;
        } data;

    protected:
        _FORCE_INLINE_ void  setIgnoreTransformNotification( bool ignore ) { data.ignoreNotification = ignore; }

        _FORCE_INLINE_ void _updateLocalTransform() const;
        _FORCE_INLINE_ void _updateRotationAndScale() const;

        void _notification( int p_what );

    public:
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
        void setGlobalRotation_degrees(const Vector3 &pEulerDeg);

        Vector3 getPosition() const;

        EulerOrder getRotationOrder() const;
        Vector3 getRotation() const;
        Vector3 getRotationDegrees() const;
        Vector3 getScale() const;

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