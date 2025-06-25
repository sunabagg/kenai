#ifndef I_VISUAL_INSTANCE_H
#define I_VISUAL_INSTANCE_H

#include <godot_cpp/classes/visual_instance3d.hpp>

#include "../core/scene_system.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::spatial
{
    void bindVisualInstance(sol::state& lua);

    class IVisualInstance : public Component
    {
    public:
        VisualInstance3D* visualInstance;

        int getLayerMask() {
            return visualInstance->get_layer_mask();
        }
        void setLayerMask(int mask) {
            visualInstance->set_layer_mask(mask);
        }

        float getSortingOffset() {
            return visualInstance->get_sorting_offset();
        }
        void setSortingOffset(float offset) {
            visualInstance->set_sorting_offset(offset);
        }

        bool getSortingUseAabbCenter() {
            return visualInstance->is_sorting_use_aabb_center();
        }

        void setSortingUseAabbCenter(bool use) {
            visualInstance->set_sorting_use_aabb_center(use);
        }

        virtual AABB onGetAabb() {
            return visualInstance->get_aabb();
        }

        AABB getAabb() {
            return onGetAabb();
        }

        bool getLayerMaskValue(int layer) {
            return visualInstance->get_layer_mask_value(layer);
        }

        void setLayerMaskValue(int layer, bool value) {
            visualInstance->set_layer_mask_value(layer, value);
        }
    };
}

#endif // I_VISUAL_INSTANCE_H