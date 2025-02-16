#ifndef I_VISUAL_INSTANCE_H
#define I_VISUAL_INSTANCE_H

#include <godot_cpp/classes/visual_instance3d.hpp>

#include "../core/scene_system.h"
#include "transform.h"

using namespace godot;
using namespace sunaba_core;

namespace sunaba_spatial
{
    void bindVisualInstance(sol::state& lua);

    class IVisualInstance : public Component
    {
    protected:
        VisualInstance3D* node;
    public:
        int getLayerMask() {
            return node->get_layer_mask();
        }
        void setLayerMask(int mask) {
            node->set_layer_mask(mask);
        }

        float getSortingOffset() {
            return node->get_sorting_offset();
        }
        void setSortingOffset(float offset) {
            node->set_sorting_offset(offset);
        }

        bool getSortingUseAabbCenter() {
            return node->is_sorting_use_aabb_center();
        }

        void setSortingUseAabbCenter(bool use) {
            node->set_sorting_use_aabb_center(use);
        }

        virtual AABB onGetAabb() {
            return node->get_aabb();
        }

        AABB getAabb() {
            return onGetAabb();
        }

        bool getLayerMaskValue(int layer) {
            return node->get_layer_mask_value(layer);
        }

        void setLayerMaskValue(int layer, bool value) {
            node->set_layer_mask_value(layer, value);
        }
    };
}

#endif // I_VISUAL_INSTANCE_H