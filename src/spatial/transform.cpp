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
}

