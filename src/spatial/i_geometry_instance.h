#ifndef I_GEOMETRY_INSTANCE_H
#define I_GEOMETRY_INSTANCE_H

#include <godot_cpp/classes/geometry_instance3d.hpp>

#include "../core/scene_system.h"
#include "i_visual_instance.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial
{
    void bindGeometryInstance(sol::state& lua);

    class IGeometryInstance : public IVisualInstance
    {
        public:
        GeometryInstance3D* geometryInstance;
        int getCastShadow() {
            return geometryInstance->get_cast_shadows_setting();
        }

        void setCastShadow(int cast) {
            geometryInstance->set_cast_shadows_setting(static_cast<GeometryInstance3D::ShadowCastingSetting>(cast));
        }

        AABB getCustomAabb() {
            return geometryInstance->get_custom_aabb();
        }

        void setCustomAabb(AABB aabb) {
            geometryInstance->set_custom_aabb(aabb);
        }

        float getExtraCullMargin() {
            return geometryInstance->get_extra_cull_margin();
        }

        void setExtraCullMargin(float margin) {
            geometryInstance->set_extra_cull_margin(margin);
        }

        int getLightmapScale() {
            return geometryInstance->get_lightmap_scale();
        }

        void setLightmapScale(int scale) {
            geometryInstance->set_lightmap_scale(static_cast<GeometryInstance3D::LightmapScale>(scale));
        }

        int getGiMode() {
            return geometryInstance->get_gi_mode(); 
        }

        void setGiMode(int mode) {
            geometryInstance->set_gi_mode(static_cast<GeometryInstance3D::GIMode>(mode));
        }

        bool getIgnoreOcclusionCulling() {
            return geometryInstance->is_ignoring_occlusion_culling();
        }

        void setIgnoreOcclusionCulling(bool ignore) {
            geometryInstance->set_ignore_occlusion_culling(ignore);
        }

        float getLodBias() {
            return geometryInstance->get_lod_bias();
        }

        void setLodBias(float bias) {
            geometryInstance->set_lod_bias(bias);
        }

        float getTransparancy() {
            return geometryInstance->get_transparency();
        }

        void setTransparancy(float transparancy) {
            geometryInstance->set_transparency(transparancy);
        }

        float getVisibilityRangeBegin() {
            return geometryInstance->get_visibility_range_begin();
        }

        void setVisibilityRangeBegin(float begin) {
            geometryInstance->set_visibility_range_begin(begin);
        }

        float getVisibilityRangeBeginMargin() {
            return geometryInstance->get_visibility_range_begin_margin();
        }

        void setVisibilityRangeBeginMargin(float margin) {
            geometryInstance->set_visibility_range_begin_margin(margin);
        }

        float getVisibilityRangeEnd() {
            return geometryInstance->get_visibility_range_end();
        }

        void setVisibilityRangeEnd(float end) {
            geometryInstance->set_visibility_range_end(end);
        }

        float getVisibilityRangeEndMargin() {
            return geometryInstance->get_visibility_range_end_margin();
        }

        void setVisibilityRangeEndMargin(float margin) {
            geometryInstance->set_visibility_range_end_margin(margin);
        }

        int getVisibilityRangeFadeMode() {
            return geometryInstance->get_visibility_range_fade_mode();
        }

        void setVisibilityRangeFadeMode(int mode) {
            geometryInstance->set_visibility_range_fade_mode(static_cast<GeometryInstance3D::VisibilityRangeFadeMode>(mode));
        }
    };
}

#endif