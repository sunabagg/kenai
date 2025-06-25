#ifndef BASE_MATERIAL3D_H
#define BASE_MATERIAL3D_H

#include <godot_cpp/classes/base_material3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotBaseMaterial3D godot::BaseMaterial3D

#include "../core/material.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindBaseMaterial3D(sol::state_view& lua);

    class BaseMaterial3D : public lucidware::core::Material {
    private:
        GodotBaseMaterial3D* material = nullptr;
    public:
        BaseMaterial3D() {
            setBaseMaterial3D(memnew(GodotBaseMaterial3D));
        }

        BaseMaterial3D(GodotBaseMaterial3D* m) {
            setBaseMaterial3D(m);
        }

        GodotBaseMaterial3D* getBaseMaterial3D() {
            return material;
        }

        void setBaseMaterial3D(GodotBaseMaterial3D* m) {
            material = m;
            material->reference();
            setMaterial(material);
        }

        Color* getAlbedoColor() {
            return new Color(material->get_albedo());
        }

        void setAlbedoColor(Color* color) {
            material->set_albedo(*color);
        }

        lucidware::core::Texture2D* getAlbedoTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_ALBEDO
                ).ptr()
            );
        }

        void setAlbedoTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_ALBEDO,
                texture->getTexture2D()
            );
        }

        bool getAlbedoTextureForceSrgb() {
            return material->get_flag(
                GodotBaseMaterial3D::FLAG_ALBEDO_TEXTURE_FORCE_SRGB
            );
        }

        void setAlbedoTextureForceSrgb(bool enable) {
            material->set_flag(
                GodotBaseMaterial3D::FLAG_ALBEDO_TEXTURE_FORCE_SRGB,
                enable
            );
        }

        bool getAlbedoTextureMsdf() {
            return material->get_flag(
                GodotBaseMaterial3D::FLAG_ALBEDO_TEXTURE_MSDF
            );
        }

        void setAlbedoTextureMsdf(bool enable) {
            material->set_flag(
                GodotBaseMaterial3D::FLAG_ALBEDO_TEXTURE_MSDF,
                enable
            );
        }

        float getAlphaAntialiasingEdge() {
            return material->get_alpha_antialiasing_edge();
        }

        void setAlphaAntialiasingEdge(float value) {
            material->set_alpha_antialiasing_edge(value);
        }

        int getAlphaAntialiasingMode() {
            return material->get_alpha_antialiasing();
        }

        void setAlphaAntialiasingMode(int mode) {
            material->set_alpha_antialiasing(static_cast<GodotBaseMaterial3D::AlphaAntiAliasing>(mode));
        }

        float getAplhaHashScale() {
            return material->get_alpha_hash_scale();
        }

        void setAlphaHashScale(float scale) {
            material->set_alpha_hash_scale(scale);
        }

        float getAlphaScissorThreshold() {
            return material->get_alpha_scissor_threshold();
        }

        void setAlphaScissorThreshold(float threshold) {
            material->set_alpha_scissor_threshold(threshold);
        }

        float getAnisotropy() {
            return material->get_anisotropy();
        }

        void setAnisotropy(float value) {
            material->set_anisotropy(value);
        }

        bool getAnisotropyEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_ANISOTROPY);
        }

        void setAnisotropyEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_ANISOTROPY, enable);
        }

        lucidware::core::Texture2D* getAnisotropyFlowmap() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_FLOWMAP
                ).ptr()
            );
        }

        void setAnisotropyFlowmap(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_FLOWMAP,
                texture->getTexture2D()
            );
        }

        bool getAoEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_AMBIENT_OCCLUSION);
        }

        void setAoEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_AMBIENT_OCCLUSION, enable);
        }

        float getAoLightAffect() {
            return material->get_ao_light_affect();
        }

        void setAoLightAffect(float value) {
            material->set_ao_light_affect(value);
        }

        bool getAoOnUv2() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_AO_ON_UV2);
        }

        void setAoOnUv2(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_AO_ON_UV2, enable);
        }

        lucidware::core::Texture2D* getAoTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_AMBIENT_OCCLUSION
                ).ptr()
            );
        }

        void setAoTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_AMBIENT_OCCLUSION,
                texture->getTexture2D()
            );
        }

        int getAoTextureChannel() {
            return material->get_ao_texture_channel();
        }

        void setAoTextureChannel(int channel) {
            material->set_ao_texture_channel(static_cast<GodotBaseMaterial3D::TextureChannel>(channel));
        }

        Color getBacklight() {
            return material->get_backlight();
        }

        void setBacklight(Color color) {
            material->set_backlight(color);
        }

        bool getBacklightEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_BACKLIGHT);
        }

        void setBacklightEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_BACKLIGHT, enable);
        }

        lucidware::core::Texture2D* getBacklightTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_BACKLIGHT
                ).ptr()
            );
        }

        void setBacklightTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_BACKLIGHT,
                texture->getTexture2D()
            );
        }

        bool getBillboardKeepScale() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_BILLBOARD_KEEP_SCALE);
        }

        void setBillboardKeepScale(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_BILLBOARD_KEEP_SCALE, enable);
        }

        int getBillboardMode() {
            return material->get_billboard_mode();
        }

        void setBillboardMode(int mode) {
            material->set_billboard_mode(static_cast<GodotBaseMaterial3D::BillboardMode>(mode));
        }

        int getBlendMode() {
            return material->get_blend_mode();
        }

        void setBlendMode(int mode) {
            material->set_blend_mode(static_cast<GodotBaseMaterial3D::BlendMode>(mode));
        }

        float getClearcoat() {
            return material->get_clearcoat();
        }

        void setClearcoat(float value) {
            material->set_clearcoat(value);
        }

        bool getClearcoatEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_CLEARCOAT);
        }

        void setClearcoatEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_CLEARCOAT, enable);
        }

        float getClearcoatRoughness() {
            return material->get_clearcoat_roughness();
        }

        void setClearcoatRoughness(float value) {
            material->set_clearcoat_roughness(value);
        }

        lucidware::core::Texture2D* getClearcoatTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_CLEARCOAT
                ).ptr()
            );
        }

        void setClearcoatTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_CLEARCOAT,
                texture->getTexture2D()
            );
        }

        int getCullMode() {
            return material->get_cull_mode();
        }

        void setCullMode(int mode) {
            material->set_cull_mode(static_cast<GodotBaseMaterial3D::CullMode>(mode));
        }

        int getDepthDrawMode() {
            return material->get_depth_draw_mode();
        }

        void setDepthDrawMode(int mode) {
            material->set_depth_draw_mode(static_cast<GodotBaseMaterial3D::DepthDrawMode>(mode));
        }

        lucidware::core::Texture2D* getDetailAlbedo() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_ALBEDO
                ).ptr()
            );
        }

        void setDetailAlbedo(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_ALBEDO,
                texture->getTexture2D()
            );
        }

        int getDetailBlendMode() {
            return material->get_detail_blend_mode();
        }

        void setDetailBlendMode(int mode) {
            material->set_detail_blend_mode(static_cast<GodotBaseMaterial3D::BlendMode>(mode));
        }

        bool getDetailEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_DETAIL);
        }

        void setDetailEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_DETAIL, enable);
        }

        lucidware::core::Texture2D* getDetailMask() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_MASK
                ).ptr()
            );
        }

        void setDetailMask(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_MASK,
                texture->getTexture2D()
            );
        }

        lucidware::core::Texture2D* getDetailNormal() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_NORMAL
                ).ptr()
            );
        }

        void setDetailNormal(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_NORMAL,
                texture->getTexture2D()
            );
        }

        int getDetailUvLayer() {
            return material->get_detail_uv();
        }

        void setDetailUvLayer(int layer) {
            material->set_detail_uv(static_cast<GodotBaseMaterial3D::DetailUV>(layer));
        }

        int getDiffuseMode() {
            return material->get_diffuse_mode();
        }

        void setDiffuseMode(int mode) {
            material->set_diffuse_mode(static_cast<GodotBaseMaterial3D::DiffuseMode>(mode));
        }

        bool getDisableAmbientLight() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_DISABLE_AMBIENT_LIGHT);
        }

        void setDisableAmbientLight(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_DISABLE_AMBIENT_LIGHT, enable);
        }

        bool getDisableFog() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_DISABLE_FOG);
        }

        void setDisableFog(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_DISABLE_FOG, enable);
        }

        bool getDisableReceiveShadows() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_DONT_RECEIVE_SHADOWS);
        }

        void setDisableReceiveShadows(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_DONT_RECEIVE_SHADOWS, enable);
        }

        float getDistanceFadeMaxDistance() {
            return material->get_distance_fade_max_distance();
        }

        void setDistanceFadeMaxDistance(float distance) {
            material->set_distance_fade_max_distance(distance);
        }

        float getDistanceFadeMinDistance() {
            return material->get_distance_fade_min_distance();
        }

        void setDistanceFadeMinDistance(float distance) {
            material->set_distance_fade_min_distance(distance);
        }

        int getDistanceFadeMode() {
            return material->get_distance_fade();
        }

        void setDistanceFadeMode(int mode) {
            material->set_distance_fade(static_cast<GodotBaseMaterial3D::DistanceFadeMode>(mode));
        }

        Color getEmission() {
            return material->get_emission();
        }

        void setEmission(Color color) {
            material->set_emission(color);
        }

        bool getEmissionEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_EMISSION);
        }

        void setEmissionEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_EMISSION, enable);
        }

        float getEmissionEnergyMultiplier() {
            return material->get_emission_energy_multiplier();
        }

        void setEmissionEnergyMultiplier(float value) {
            material->set_emission_energy_multiplier(value);
        }

        float getEmissionIntensity() {
            return material->get_emission_intensity();
        }

        void setEmissionIntensity(float value) {
            material->set_emission_intensity(value);
        }

        bool getEmissionOnUv2() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_EMISSION_ON_UV2);
        }

        void setEmissionOnUv2(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_EMISSION_ON_UV2, enable);
        }

        int getEmissionOperator() {
            return material->get_emission_operator();
        }

        void setEmissionOperator(int operator_) {
            material->set_emission_operator(static_cast<GodotBaseMaterial3D::EmissionOperator>(operator_));
        }

        lucidware::core::Texture2D* getEmissionTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_EMISSION
                ).ptr()
            );
        }

        void setEmissionTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_EMISSION,
                texture->getTexture2D()
            );
        }

        bool getFixedSize() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_FIXED_SIZE);
        }

        void setFixedSize(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_FIXED_SIZE, enable);
        }

        bool getGrow() {
            return material->is_grow_enabled();
        }

        void setGrow(bool enable) {
            material->set_grow_enabled(enable);
        }

        float getGrowAmount() {
            return material->get_grow();
        }

        void setGrowAmount(float amount) {
            material->set_grow(amount);
        }

        bool getHeightmapDeepParallax() {
            return material->is_heightmap_deep_parallax_enabled();
        }
        
        void setHeightmapDeepParallax(bool enable) {
            material->set_heightmap_deep_parallax(enable);
        }

        bool getHeightmapEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_HEIGHT_MAPPING);
        }

        void setHeightmapEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_HEIGHT_MAPPING, enable);
        }

        bool getHeightmapFlipBinormal() {
            return material->get_heightmap_deep_parallax_flip_binormal();
        }

        void setHeightmapFlipBinormal(bool enable) {
            material->set_heightmap_deep_parallax_flip_binormal(enable);
        }

        bool getHeightmapFlipTangent() {
            return material->get_heightmap_deep_parallax_flip_tangent();
        }

        void setHeightmapFlipTangent(bool enable) {
            material->set_heightmap_deep_parallax_flip_tangent(enable);
        }

        bool getHeightmapFlipTexture() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_INVERT_HEIGHTMAP);
        }

        void setHeightmapFlipTexture(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_INVERT_HEIGHTMAP, enable);
        }

        int getHeightmapMaxLayers() {
            return material->get_heightmap_deep_parallax_max_layers();
        }
        
        void setHeightmapMaxLayers(int layers) {
            material->set_heightmap_deep_parallax_max_layers(layers);
        }

        int getHeightmapMinLayers() {
            return material->get_heightmap_deep_parallax_min_layers();
        }

        void setHeightmapMinLayers(int layers) {
            material->set_heightmap_deep_parallax_min_layers(layers);
        }

        float getHeightmapScale() {
            return material->get_heightmap_scale();
        }

        void setHeightmapScale(float scale) {
            material->set_heightmap_scale(scale);
        }

        lucidware::core::Texture2D* getHeightmapTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_HEIGHTMAP
                ).ptr()
            );
        }

        void setHeightmapTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_HEIGHTMAP,
                texture->getTexture2D()
            );
        }

        float getMetallic() {
            return material->get_metallic();
        }

        void setMetallic(float value) {
            material->set_metallic(value);
        }

        float getMetallicSpecular() {
            return material->get_specular();
        }

        void setMetallicSpecular(float value) {
            material->set_specular(value);
        }

        lucidware::core::Texture2D* getMetallicTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_METALLIC
                ).ptr()
            );
        }

        void setMetallicTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_METALLIC,
                texture->getTexture2D()
            );
        }

        int getMetallicTextureChannel() {
            return material->get_metallic_texture_channel();
        }

        void setMetallicTextureChannel(int channel) {
            material->set_metallic_texture_channel(static_cast<GodotBaseMaterial3D::TextureChannel>(channel));
        }

        float getMsdfOutlineSize() {
            return material->get_msdf_outline_size();
        }

        void setMsdfOutlineSize(float size) {
            material->set_msdf_outline_size(size);
        }

        float getMsdfPixelRange() {
            return material->get_msdf_pixel_range();
        }

        void setMsdfPixelRange(float range) {
            material->set_msdf_pixel_range(range);
        }

        bool getNoDepthTest() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_DISABLE_DEPTH_TEST);
        }

        void setNoDepthTest(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_DISABLE_DEPTH_TEST, enable);
        }

        bool getNormalEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_NORMAL_MAPPING);
        }

        void setNormalEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_NORMAL_MAPPING, enable);
        }

        float getNormalScale() {
            return material->get_normal_scale();
        }

        void setNormalScale(float scale) {
            material->set_normal_scale(scale);
        }

        lucidware::core::Texture2D* getNormalTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_NORMAL
                ).ptr()
            );
        }

        void setNormalTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_NORMAL,
                texture->getTexture2D()
            );
        }

        lucidware::core::Texture2D* getOrmTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_ORM
                ).ptr()
            );
        }

        void setOrmTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_ORM,
                texture->getTexture2D()
            );
        }

        int getParticlesAnimHFrames() {
            return material->get_particles_anim_h_frames();
        }

        void setParticlesAnimHFrames(int frames) {
            material->set_particles_anim_h_frames(frames);
        }

        bool getParticlesAnimLoop() {
            return material->get_particles_anim_loop();
        }

        void setParticlesAnimLoop(bool enable) {
            material->set_particles_anim_loop(enable);
        }

        int getParticlesAnimVFrames() {
            return material->get_particles_anim_v_frames();
        }

        void setParticlesAnimVFrames(int frames) {
            material->set_particles_anim_v_frames(frames);
        }

        float getPointSize() {
            return material->get_point_size();
        }

        void setPointSize(float size) {
            material->set_point_size(size);
        }

        float getProximityFadeDistance() {
            return material->get_proximity_fade_distance();
        }

        void setProximityFadeDistance(float distance) {
            material->set_proximity_fade_distance(distance);
        }

        bool getProximityFadeEnabled() {
            return material->is_proximity_fade_enabled();
        }

        void setProximityFadeEnabled(bool enable) {
            material->set_proximity_fade_enabled(enable);
        }

        bool getRefractionEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_REFRACTION);
        }

        void setRefractionEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_REFRACTION, enable);
        }

        float getRefractionScale() {
            return material->get_refraction();
        }

        void setRefractionScale(float scale) {
            material->set_refraction(scale);
        }

        lucidware::core::Texture2D* getRefractionTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_REFRACTION
                ).ptr()
            );
        }

        void setRefractionTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_REFRACTION,
                texture->getTexture2D()
            );
        }

        int getRefractionTextureChannel() {
            return material->get_refraction_texture_channel();
        }

        void setRefractionTextureChannel(int channel) {
            material->set_refraction_texture_channel(static_cast<GodotBaseMaterial3D::TextureChannel>(channel));
        }

        float getRim() {
            return material->get_rim();
        }

        void setRim(float value) {
            material->set_rim(value);
        }

        bool getRimEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_RIM);
        }

        void setRimEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_RIM, enable);
        }

        lucidware::core::Texture2D* getRimTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_RIM
                ).ptr()
            );
        }

        void setRimTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_RIM,
                texture->getTexture2D()
            );
        }

        float getRimTint() {
            return material->get_rim_tint();
        }

        void setRimTint(float value) {
            material->set_rim_tint(value);
        }

        float getRoughness() {
            return material->get_roughness();
        }

        void setRoughness(float value) {
            material->set_roughness(value);
        }

        lucidware::core::Texture2D* getRoughnessTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_ROUGHNESS
                ).ptr()
            );
        }

        void setRoughnessTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_ROUGHNESS,
                texture->getTexture2D()
            );
        }

        int getRoughnessTextureChannel() {
            return material->get_roughness_texture_channel();
        }

        void setRoughnessTextureChannel(int channel) {
            material->set_roughness_texture_channel(static_cast<GodotBaseMaterial3D::TextureChannel>(channel));
        }

        int getShadingMode() {
            return material->get_shading_mode();
        }

        void setShadingMode(int mode) {
            material->set_shading_mode(static_cast<GodotBaseMaterial3D::ShadingMode>(mode));
        }

        bool getShadowToOpacity() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_USE_SHADOW_TO_OPACITY);
        }

        void setShadowToOpacity(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_USE_SHADOW_TO_OPACITY, enable);
        }

        int getSpecularMode() {
            return material->get_specular_mode();
        }

        void setSpecularMode(int mode) {
            material->set_specular_mode(static_cast<GodotBaseMaterial3D::SpecularMode>(mode));
        }

        bool getSubsurfScatterEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_SUBSURFACE_SCATTERING);
        }

        void setSubsurfScatterEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_SUBSURFACE_SCATTERING, enable);
        }

        bool getSubsurfScatterSkinMode() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_SUBSURFACE_MODE_SKIN);
        }

        void setSubsurfScatterSkinMode(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_SUBSURFACE_MODE_SKIN, enable);
        }

        float getSubsurfScatterStrength() {
            return material->get_subsurface_scattering_strength();
        }

        void setSubsurfScatterStrength(float value) {
            material->set_subsurface_scattering_strength(value);
        }

        lucidware::core::Texture2D* getSubsurfScatterTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_SUBSURFACE_SCATTERING
                ).ptr()
            );
        }

        void setSubsurfScatterTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_SUBSURFACE_SCATTERING,
                texture->getTexture2D()
            );
        }

        float getSubsurfScatterTransmittanceBoost() {
            return material->get_transmittance_boost();
        }

        void setSubsurfScatterTransmittanceBoost(float value) {
            material->set_transmittance_boost(value);
        }

        Color getSubsurfScatterTransmittanceColor() {
            return material->get_transmittance_color();
        }

        void setSubsurfScatterTransmittanceColor(Color color) {
            material->set_transmittance_color(color);
        }

        float getSubsurfScatterTransmittanceDepth() {
            return material->get_transmittance_depth();
        }

        void setSubsurfScatterTransmittanceDepth(float value) {
            material->set_transmittance_depth(value);
        }

        bool getSubsurfScatterTransmittanceEnabled() {
            return material->get_feature(GodotBaseMaterial3D::FEATURE_SUBSURFACE_TRANSMITTANCE);
        }

        void setSubsurfScatterTransmittanceEnabled(bool enable) {
            material->set_feature(GodotBaseMaterial3D::FEATURE_SUBSURFACE_TRANSMITTANCE, enable);
        }

        lucidware::core::Texture2D* getSubsurfScatterTransmittanceTexture() {
            return new lucidware::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_SUBSURFACE_TRANSMITTANCE
                ).ptr()
            );
        }

        void setSubsurfScatterTransmittanceTexture(lucidware::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_SUBSURFACE_TRANSMITTANCE,
                texture->getTexture2D()
            );
        }

        int getTextureFilter() {
            return material->get_texture_filter();
        }

        void setTextureFilter(int filter) {
            material->set_texture_filter(static_cast<GodotBaseMaterial3D::TextureFilter>(filter));
        }

        bool getTextureRepeat() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_USE_TEXTURE_REPEAT);
        }

        void setTextureRepeat(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_USE_TEXTURE_REPEAT, enable);
        }

        int getTransparency() {
            return material->get_transparency();
        }

        void setTransparency(int mode) {
            material->set_transparency(static_cast<GodotBaseMaterial3D::Transparency>(mode));
        }

        bool getUseParticleTrails() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_PARTICLE_TRAILS_MODE);
        }

        void setUseParticleTrails(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_PARTICLE_TRAILS_MODE, enable);
        }

        bool getUsePointSize() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_USE_POINT_SIZE);
        }

        void setUsePointSize(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_USE_POINT_SIZE, enable);
        }

        Vector3 getUv1Offset() {
            return material->get_uv1_offset();
        }

        void setUv1Offset(Vector3 offset) {
            material->set_uv1_offset(offset);
        }

        Vector3 getUv1Scale() {
            return material->get_uv1_scale();
        }

        void setUv1Scale(Vector3 scale) {
            material->set_uv1_scale(scale);
        }

        bool getUv1Triplanar() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_UV1_USE_TRIPLANAR);
        }

        void setUv1Triplanar(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_UV1_USE_TRIPLANAR, enable);
        }

        float getUv1TriplanarSharpness() {
            return material->get_uv1_triplanar_blend_sharpness();
        }

        void setUv1TriplanarSharpness(float sharpness) {
            material->set_uv1_triplanar_blend_sharpness(sharpness);
        }

        bool getUv1WorldTriplanar() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_UV1_USE_WORLD_TRIPLANAR);
        }

        void setUv1WorldTriplanar(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_UV1_USE_WORLD_TRIPLANAR, enable);
        }

        Vector3 getUv2Offset() {
            return material->get_uv2_offset();
        }

        void setUv2Offset(Vector3 offset) {
            material->set_uv2_offset(offset);
        }

        Vector3 getUv2Scale() {
            return material->get_uv2_scale();
        }

        void setUv2Scale(Vector3 scale) {
            material->set_uv2_scale(scale);
        }

        bool getUv2Triplanar() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_UV2_USE_TRIPLANAR);
        }

        void setUv2Triplanar(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_UV2_USE_TRIPLANAR, enable);
        }

        float getUv2TriplanarSharpness() {
            return material->get_uv2_triplanar_blend_sharpness();
        }

        void setUv2TriplanarSharpness(float sharpness) {
            material->set_uv2_triplanar_blend_sharpness(sharpness);
        }

        bool getUv2WorldTriplanar() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_UV2_USE_WORLD_TRIPLANAR);
        }

        void setUv2WorldTriplanar(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_UV2_USE_WORLD_TRIPLANAR, enable);
        }

        bool getVertexColorIsSrgb() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_SRGB_VERTEX_COLOR);
        }

        void setVertexColorIsSrgb(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_SRGB_VERTEX_COLOR, enable);
        }

        bool getVertexColorUseAsAlbedo() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_ALBEDO_FROM_VERTEX_COLOR);
        }

        void setVertexColorUseAsAlbedo(bool enable) {
            material->set_flag(GodotBaseMaterial3D::FLAG_ALBEDO_FROM_VERTEX_COLOR, enable);
        }

        bool getFeature(int feature) {
            return material->get_feature(static_cast<GodotBaseMaterial3D::Feature>(feature));
        }

        bool getFlag(int flag) {
            return material->get_flag(static_cast<GodotBaseMaterial3D::Flags>(flag));
        }

        lucidware::core::Texture2D* getTexture(int param) {
            return new lucidware::core::Texture2D(
                material->get_texture(static_cast<GodotBaseMaterial3D::TextureParam>(param)).ptr()
            );
        }

        void setFeature(int feature, bool enable) {
            material->set_feature(static_cast<GodotBaseMaterial3D::Feature>(feature), enable);
        }

        void setFlag(int flag, bool enable) {
            material->set_flag(static_cast<GodotBaseMaterial3D::Flags>(flag), enable);
        }

        void setTexture(int param, lucidware::core::Texture2D* texture) {
            material->set_texture(
                static_cast<GodotBaseMaterial3D::TextureParam>(param),
                texture->getTexture2D()
            );
        }
    };
}

#endif // BASE_MATERIAL3D_H