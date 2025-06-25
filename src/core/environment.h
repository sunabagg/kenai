#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <godot_cpp/classes/environment.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotEnvironment godot::Environment

#include "resource.h"
#include "texture.h"
#include <godot_cpp/classes/texture.hpp>
#include "../spatial/sky.h"

using namespace godot; 

namespace lucidfx::core {
    void bindEnvironment(sol::state_view& lua);

    class Environment : public Resource {
    private:
        GodotEnvironment* environment = nullptr;
    public:
        Environment() {
            setEnvironment(memnew(GodotEnvironment));
        }

        Environment(GodotEnvironment* env) {
            setEnvironment(env);
        }

        GodotEnvironment* getEnvironment() {
            return environment;
        }

        void setEnvironment(GodotEnvironment* env) {
            environment = env;
            environment->reference();
            setResource(env);
        }

        float getAdjustmentBrightness() {
            return environment->get_adjustment_brightness();
        }

        void setAdjustmentBrightness(float brightness) {
            environment->set_adjustment_brightness(brightness);
        }

        lucidfx::core::Texture* getAdjustmentColorCorrection() {
            return new lucidfx::core::Texture(environment->get_adjustment_color_correction().ptr());
        }

        void setAdjustmentColorCorrection(lucidfx::core::Texture* texture) {
            environment->set_adjustment_color_correction(Ref<GodotTexture>(texture->getTexture()));
        }

        float getAdjustmentContrast() {
            return environment->get_adjustment_contrast();
        }

        void setAdjustmentContrast(float contrast) {
            environment->set_adjustment_contrast(contrast);
        }

        bool getAdjustmentEnabled() {
            return environment->is_adjustment_enabled();
        }

        void setAdjustmentEnabled(bool enabled) {
            environment->set_adjustment_enabled(enabled);
        }

        float getAdjustmentSaturation() {
            return environment->get_adjustment_saturation();
        }

        void setAdjustmentSaturation(float saturation) {
            environment->set_adjustment_saturation(saturation);
        }

        Color getAmbientLightColor() {
            return environment->get_ambient_light_color();
        }

        void setAmbientLightColor(Color color) {
            environment->set_ambient_light_color(color);
        }

        float getAmbientLightEnergy() {
            return environment->get_ambient_light_energy();
        }

        void setAmbientLightEnergy(float energy) {
            environment->set_ambient_light_energy(energy);
        }

        float getAmbientLightSkyContribution() {
            return environment->get_ambient_light_sky_contribution();
        }

        void setAmbientLightSkyContribution(float contribution) {
            environment->set_ambient_light_sky_contribution(contribution);
        }

        int getAmbientLightSource() {
            return environment->get_ambient_source();
        }

        void setAmbientLightSource(int source) {
            environment->set_ambient_source(static_cast<GodotEnvironment::AmbientSource>(source));
        }

        int getBackgroundCameraFeedId() {
            return environment->get_camera_feed_id();
        }

        void setBackgroundCameraFeedId(int id) {
            environment->set_camera_feed_id(id);
        }

        int getBackgroundCanvasMaxLayer() {
            return environment->get_canvas_max_layer();
        }

        void setBackgroundCanvasMaxLayer(int layer) {
            environment->set_canvas_max_layer(layer);
        }

        Color getBackgroundColor() {
            return environment->get_bg_color();
        }

        void setBackgroundColor(Color color) {
            environment->set_bg_color(color);
        }

        float getBackgroundEnergyMultiplier() {
            return environment->get_bg_energy_multiplier();
        }

        void setBackgroundEnergyMultiplier(float multiplier) {
            environment->set_bg_energy_multiplier(multiplier);
        }

        float getBackgroundIntensity() {
            return environment->get_bg_intensity();
        }

        void setBackgroundIntensity(float intensity) {
            environment->set_bg_intensity(intensity);
        }

        int getBackgroundMode() {
            return environment->get_background();
        }

        void setBackgroundMode(int mode) {
            environment->set_background(static_cast<GodotEnvironment::BGMode>(mode));
        }

        float getFogAerialPerspective() {
            return environment->get_fog_aerial_perspective();
        }

        void setFogAerialPerspective(float perspective) {
            environment->set_fog_aerial_perspective(perspective);
        }

        float getFogDensity() {
            return environment->get_fog_density();
        }

        void setFogDensity(float density) {
            environment->set_fog_density(density);
        }

        float getFogDepthBegin() {
            return environment->get_fog_depth_begin();
        }

        void setFogDepthBegin(float begin) {
            environment->set_fog_depth_begin(begin);
        }

        float getFogDepthCurve() {
            return environment->get_fog_depth_curve();
        }

        void setFogDepthCurve(float curve) {
            environment->set_fog_depth_curve(curve);
        }

        float getFogDepthEnd() {
            return environment->get_fog_depth_end();
        }

        void setFogDepthEnd(float end) {
            environment->set_fog_depth_end(end);
        }

        bool getFogEnabled() {
            return environment->is_fog_enabled();
        }

        void setFogEnabled(bool enabled) {
            environment->set_fog_enabled(enabled);
        }

        float getFogHeight() {
            return environment->get_fog_height();
        }

        void setFogHeight(float height) {
            environment->set_fog_height(height);
        }

        float getFogHeightDensity() {
            return environment->get_fog_height_density();
        }

        void setFogHeightDensity(float density) {
            environment->set_fog_height_density(density);
        }

        Color getFogLightColor() {
            return environment->get_fog_light_color();
        }

        void setFogLightColor(Color color) {
            environment->set_fog_light_color(color);
        }

        float getFogLightEnergy() {
            return environment->get_fog_light_energy();
        }

        void setFogLightEnergy(float energy) {
            environment->set_fog_light_energy(energy);
        }

        int getFogMode() {
            return environment->get_fog_mode();
        }

        void setFogMode(int mode) {
            environment->set_fog_mode(static_cast<GodotEnvironment::FogMode>(mode));
        }

        float getFogSkyAffect() {
            return environment->get_fog_sky_affect();
        }

        void setFogSkyAffect(float affect) {
            environment->set_fog_sky_affect(affect);
        }

        float getFogSunScatter() {
            return environment->get_fog_sun_scatter();
        }

        void setFogSunScatter(float scatter) {
            environment->set_fog_sun_scatter(scatter);
        }

        int getGlowBlendMode() {
            return environment->get_glow_blend_mode();
        }

        void setGlowBlendMode(int mode) {
            environment->set_glow_blend_mode(static_cast<GodotEnvironment::GlowBlendMode>(mode));
        }

        float getGlowBloom() {
            return environment->get_glow_bloom();
        }

        void setGlowBloom(float bloom) {
            environment->set_glow_bloom(bloom);
        }

        bool getGlowEnabled() {
            return environment->is_glow_enabled();
        }

        void setGlowEnabled(bool enabled) {
            environment->set_glow_enabled(enabled);
        }

        float getGlowHdrLuminanceCap() {
            return environment->get_glow_hdr_luminance_cap();
        }

        void setGlowHdrLuminanceCap(float cap) {
            environment->set_glow_hdr_luminance_cap(cap);
        }

        float getGlowHdrScale() {
            return environment->get_glow_hdr_bleed_scale();
        }

        void setGlowHdrScale(float scale) {
            environment->set_glow_hdr_bleed_scale(scale);
        }

        float getGlowHdrThreshold() {
            return environment->get_glow_hdr_bleed_threshold();
        }

        void setGlowHdrThreshold(float threshold) {
            environment->set_glow_hdr_bleed_threshold(threshold);
        }

        float getGlowIntensity() {
            return environment->get_glow_intensity();
        }

        void setGlowIntensity(float intensity) {
            environment->set_glow_intensity(intensity);
        }
        
        float getGlowLevel1() {
            return environment->get_glow_level(1);
        }

        void setGlowLevel1(float level) {
            environment->set_glow_level(1, level);
        }

        float getGlowLevel2() {
            return environment->get_glow_level(2);
        }

        void setGlowLevel2(float level) {
            environment->set_glow_level(2, level);
        }

        float getGlowLevel3() {
            return environment->get_glow_level(3);
        }

        void setGlowLevel3(float level) {
            environment->set_glow_level(3, level);
        }

        float getGlowLevel4() {
            return environment->get_glow_level(4);
        }

        void setGlowLevel4(float level) {
            environment->set_glow_level(4, level);
        }

        float getGlowLevel5() {
            return environment->get_glow_level(5);
        }

        void setGlowLevel5(float level) {
            environment->set_glow_level(5, level);
        }

        float getGlowLevel6() {
            return environment->get_glow_level(6);
        }

        void setGlowLevel6(float level) {
            environment->set_glow_level(6, level);
        }

        float getGlowLevel7() {
            return environment->get_glow_level(7);
        }

        void setGlowLevel7(float level) {
            environment->set_glow_level(7, level);
        }

        Texture* getGlowMap() {
            return new Texture(environment->get_glow_map().ptr());
        }

        void setGlowMap(Texture* texture) {
            environment->set_glow_map(Ref<GodotTexture>(texture->getTexture()));
        }

        bool getGlowMapStrength() {
            return environment->get_glow_map_strength();
        }

        void setGlowMapStrength(bool enabled) {
            environment->set_glow_map_strength(enabled);
        }

        float getGlowMix() {
            return environment->get_glow_mix();
        }

        void setGlowMix(float mix) {
            environment->set_glow_mix(mix);
        }

        bool getGlowNormalized() {
            return environment->is_glow_normalized();
        }

        void setGlowNormalized(bool normalized) {
            environment->set_glow_normalized(normalized);
        }

        float getGlowStrength() {
            return environment->get_glow_strength();
        }

        void setGlowStrength(float strength) {
            environment->set_glow_strength(strength);
        }

        int getReflectedLightSource() {
            return environment->get_reflection_source();
        }

        void setReflectedLightSource(int source) {
            environment->set_reflection_source(static_cast<GodotEnvironment::ReflectionSource>(source));
        }

        float getDynamicGiBounceFeedback() {
            return environment->get_sdfgi_bounce_feedback();
        }

        void setDynamicGiBounceFeedback(float feedback) {
            environment->set_sdfgi_bounce_feedback(feedback);
        }

        float getDynamicGiCascade0Distance() {
            return environment->get_sdfgi_cascade0_distance();
        }

        void setDynamicGiCascade0Distance(float distance) {
            environment->set_sdfgi_cascade0_distance(distance);
        }

        int getDynamicGiCascades() {
            return environment->get_sdfgi_cascades();
        }

        void setDynamicGiCascades(int cascades) {
            environment->set_sdfgi_cascades(cascades);
        }

        bool getDynamicGiEnabled() {
            return environment->is_sdfgi_enabled();
        }

        void setDynamicGiEnabled(bool enabled) {
            environment->set_sdfgi_enabled(enabled);
        }

        float getDynamicGiEnergy() {
            return environment->get_sdfgi_energy();
        }

        void setDynamicGiEnergy(float energy) {
            environment->set_sdfgi_energy(energy);
        }

        float getDynamicGiMaxDistance() {
            return environment->get_sdfgi_max_distance();
        }

        void setDynamicGiMaxDistance(float distance) {
            environment->set_sdfgi_max_distance(distance);
        }

        float getDynamicGiMinCellSize() {
            return environment->get_sdfgi_min_cell_size();
        }

        void setDynamicGiMinCellSize(float size) {
            environment->set_sdfgi_min_cell_size(size);
        }

        float getDynamicGiNormalBias() {
            return environment->get_sdfgi_normal_bias();
        }

        void setDynamicGiNormalBias(float bias) {
            environment->set_sdfgi_normal_bias(bias);
        }

        float getDynamicGiProbeBias() {
            return environment->get_sdfgi_probe_bias();
        }

        void setDynamicGiProbeBias(float bias) {
            environment->set_sdfgi_probe_bias(bias);
        }

        bool getDynamicGiUseOcclusion() {
            return environment->is_sdfgi_using_occlusion();
        }

        void setDynamicGiUseOcclusion(bool enabled) {
            environment->set_sdfgi_use_occlusion(enabled);
        }

        int getDynamicGiYScale() {
            return environment->get_sdfgi_y_scale();
        }

        void setDynamicGiYScale(int scale) {
            environment->set_sdfgi_y_scale(static_cast<GodotEnvironment::SDFGIYScale>(scale));
        }

        lucidfx::spatial::Sky* getSky() {
            return new lucidfx::spatial::Sky(environment->get_sky().ptr());
        }

        void setSky(lucidfx::spatial::Sky* sky) {
            environment->set_sky(sky->getSky());
        }

        float getSkyCustomFov() {
            return environment->get_sky_custom_fov();
        }

        void setSkyCustomFov(float fov) {
            environment->set_sky_custom_fov(fov);
        }

        Vector3 getSkyRotation() {
            return environment->get_sky_rotation();
        }

        void setSkyRotation(Vector3 rotation) {
            environment->set_sky_rotation(rotation);
        }

        float getSsaoAoChannelAffect() {
            return environment->get_ssao_ao_channel_affect();
        }

        void setSsaoAoChannelAffect(float affect) {
            environment->set_ssao_ao_channel_affect(affect);
        }

        float getSsaoDetail() {
            return environment->get_ssao_detail();
        }

        void setSsaoDetail(float detail) {
            environment->set_ssao_detail(detail);
        }

        bool getSsaoEnabled() {
            return environment->is_ssao_enabled();
        }

        void setSsaoEnabled(bool enabled) {
            environment->set_ssao_enabled(enabled);
        }

        float getSsaoHorizon() {
            return environment->get_ssao_horizon();
        }

        void setSsaoHorizon(float horizon) {
            environment->set_ssao_horizon(horizon);
        }

        float getSsaoIntensity() {
            return environment->get_ssao_intensity();
        }

        void setSsaoIntensity(float intensity) {
            environment->set_ssao_intensity(intensity);
        }

        float getSsaoLightAffect() {
            return environment->get_ssao_direct_light_affect();
        }

        void setSsaoLightAffect(float affect) {
            environment->set_ssao_direct_light_affect(affect);
        }

        float getSsaoPower() {
            return environment->get_ssao_power();
        }

        void setSsaoPower(float power) {
            environment->set_ssao_power(power);
        }

        float getSsaoRadius() {
            return environment->get_ssao_radius();
        }

        void setSsaoRadius(float radius) {
            environment->set_ssao_radius(radius);
        }

        float getSsaoSharpness() {
            return environment->get_ssao_sharpness();
        }

        void setSsaoSharpness(float sharpness) {
            environment->set_ssao_sharpness(sharpness);
        }

        bool getSsilEnabled() {
            return environment->is_ssil_enabled();
        }

        void setSsilEnabled(bool enabled) {
            environment->set_ssil_enabled(enabled);
        }

        float getSsilIntensity() {
            return environment->get_ssil_intensity();
        }

        void setSsilIntensity(float intensity) {
            environment->set_ssil_intensity(intensity);
        }

        float getSsilNormalRejection() {
            return environment->get_ssil_normal_rejection();
        }

        void setSsilNormalRejection(float rejection) {
            environment->set_ssil_normal_rejection(rejection);
        }

        float getSsilRadius() {
            return environment->get_ssil_radius();
        }

        void setSsilRadius(float radius) {
            environment->set_ssil_radius(radius);
        }

        float getSsilSharpness() {
            return environment->get_ssil_sharpness();
        }

        void setSsilSharpness(float sharpness) {
            environment->set_ssil_sharpness(sharpness);
        }

        float getSsrDepthTolerance() {
            return environment->get_ssr_depth_tolerance();
        }

        void setSsrDepthTolerance(float tolerance) {
            environment->set_ssr_depth_tolerance(tolerance);
        }

        bool getSsrEnabled() {
            return environment->is_ssr_enabled();
        }

        void setSsrEnabled(bool enabled) {
            environment->set_ssr_enabled(enabled);
        }

        float getSsrFadeIn() {
            return environment->get_ssr_fade_in();
        }

        void setSsrFadeIn(float fadeIn) {
            environment->set_ssr_fade_in(fadeIn);
        }

        float getSsrFadeOut() {
            return environment->get_ssr_fade_out();
        }

        void setSsrFadeOut(float fadeOut) {
            environment->set_ssr_fade_out(fadeOut);
        }

        int getSsrMaxSteps() {
            return environment->get_ssr_max_steps();
        }

        void setSsrMaxSteps(int steps) {
            environment->set_ssr_max_steps(steps);
        }

        float getTonemapExposure() {
            return environment->get_tonemap_exposure();
        }

        void setTonemapExposure(float exposure) {
            environment->set_tonemap_exposure(exposure);
        }

        int getTonemapMode() {
            return environment->get_tonemapper();
        }

        void setTonemapMode(int mode) {
            environment->set_tonemapper(static_cast<GodotEnvironment::ToneMapper>(mode));
        }

        float getTonemapWhite() {
            return environment->get_tonemap_white();
        }

        void setTonemapWhite(float white) {
            environment->set_tonemap_white(white);
        }

        Color getVolumetricFogAlbedo() {
            return environment->get_volumetric_fog_albedo();
        }

        void setVolumetricFogAlbedo(Color albedo) {
            environment->set_volumetric_fog_albedo(albedo);
        }

        float getVolumetricFogAmbientInject() {
            return environment->get_volumetric_fog_ambient_inject();
        }

        void setVolumetricFogAmbientInject(float inject) {
            environment->set_volumetric_fog_ambient_inject(inject);
        }

        float getVolumetricFogAnisotropy() {
            return environment->get_volumetric_fog_anisotropy();
        }

        void setVolumetricFogAnisotropy(float anisotropy) {
            environment->set_volumetric_fog_anisotropy(anisotropy);
        }

        float getVolumetricFogDensity() {
            return environment->get_volumetric_fog_density();
        }

        void setVolumetricFogDensity(float density) {
            environment->set_volumetric_fog_density(density);
        }

        float getVolumetricFogDetailSpread() {
            return environment->get_volumetric_fog_detail_spread();
        }

        void setVolumetricFogDetailSpread(float spread) {
            environment->set_volumetric_fog_detail_spread(spread);
        }

        Color getVolumetricFogEmission() {
            return environment->get_volumetric_fog_emission();
        }

        void setVolumetricFogEmission(Color emission) {
            environment->set_volumetric_fog_emission(emission);
        }

        bool getVolumetricFogEnabled() {
            return environment->is_volumetric_fog_enabled();
        }

        void setVolumetricFogEnabled(bool enabled) {
            environment->set_volumetric_fog_enabled(enabled);
        }

        float getVolumetricFogGiInject() {
            return environment->get_volumetric_fog_gi_inject();
        }

        void setVolumetricFogGiInject(float inject) {
            environment->set_volumetric_fog_gi_inject(inject);
        }

        float getVolumetricFogLength() {
            return environment->get_volumetric_fog_length();
        }

        void setVolumetricFogLength(float length) {
            environment->set_volumetric_fog_length(length);
        }

        float getVolumetricFogSkyAffect() {
            return environment->get_volumetric_fog_sky_affect();
        }

        void setVolumetricFogSkyAffect(float affect) {
            environment->set_volumetric_fog_sky_affect(affect);
        }

        float getVolumetricFogTemporalReprojectionAmount() {
            return environment->get_volumetric_fog_temporal_reprojection_amount();
        }

        void setVolumetricFogTemporalReprojectionAmount(float amount) {
            environment->set_volumetric_fog_temporal_reprojection_amount(amount);
        }

        bool getVolumetricFogTemporalReprojectionEnabled() {
            return environment->is_volumetric_fog_temporal_reprojection_enabled();
        }

        void setVolumetricFogTemporalReprojectionEnabled(bool enabled) {
            environment->set_volumetric_fog_temporal_reprojection_enabled(enabled);
        }

        float getGlowLevel(int idx) {
            return environment->get_glow_level(idx);
        }

        void setGlowLevel(int idx, float level) {
            environment->set_glow_level(idx, level);
        }
    };
}

#endif // ENVIRONMENT_H