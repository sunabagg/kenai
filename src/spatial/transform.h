#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <vector>

#include "../core/scene_system.h"

using namespace godot;
using namespace newhaven_core;

namespace newhaven_spatial
{
    class SpatialTransform : public Component
    {
    private:
        struct Data
        {
            mutable Transform3D global_transform;
            mutable Transform3D local_transform;
            mutable EulerOrder euler_rotation_order = EulerOrder::YXZ;
            mutable Vector3 euler_rotation;
            mutable Vector3 scale = Vector3( 1, 1, 1 );

            Viewport *viewport = nullptr;

            bool top_level = false;
            bool inside_world = false;

            RID visibility_parent;

            SpatialTransform *parentTransform = nullptr;
            std::vector<SpatialTransform *> children;

            bool ignore_notification = false;
            bool notify_local_transform = false;
            bool notify_transform = false;

            bool visible = true;
            bool disable_scale = false;
        } data;

    protected:
        _FORCE_INLINE_ void  set_ignore_transform_notification( bool ignore ) { data.ignore_notification = ignore; }

        _FORCE_INLINE_ void _update_local_transform() const;
        _FORCE_INLINE_ void _update_rotation_and_scale() const;

        void _notification( int p_what );

    public:
        enum
        {
            NOTIFICATION_TRANSFORM_CHANGED = SceneTree::NOTIFICATION_TRANSFORM_CHANGED,
            NOTIFICATION_ENTER_WORLD = 41,
            NOTIFICATION_EXIT_WORLD = 42,
            NOTIFICATION_VISIBILITY_CHANGED = 43,
            NOTIFICATION_LOCAL_TRANSFORM_CHANGED = 44,
        };

        SpatialTransform *get_parent_transform() const;

        Ref<World3D> get_world() const;

        void set_position(const Vector3 &p_position);
    };
}

#endif // TRANSFORM_H