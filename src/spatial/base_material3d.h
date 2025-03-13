#ifndef BASE_MATERIAL3D_H
#define BASE_MATERIAL3D_H

#include <godot_cpp/classes/base_material3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotBaseMaterial3D godot::BaseMaterial3D

#include "../core/material.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::spatial {
    void bindBaseMaterial3D(sol::state_view& lua);

    class BaseMaterial3D : public sunaba::core::Material {
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

        sunaba::core::Texture2D* getAlbedoTexture() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_ALBEDO
                ).ptr()
            );
        }

        void setAlbedoTexture(sunaba::core::Texture2D* texture) {
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

        sunaba::core::Texture2D* getAnisotropyFlowmap() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_FLOWMAP
                ).ptr()
            );
        }

        void setAnisotropyFlowmap(sunaba::core::Texture2D* texture) {
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

        sunaba::core::Texture2D* getAoTexture() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_AMBIENT_OCCLUSION
                ).ptr()
            );
        }

        void setAoTexture(sunaba::core::Texture2D* texture) {
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

        sunaba::core::Texture2D* getBacklightTexture() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_BACKLIGHT
                ).ptr()
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

        sunaba::core::Texture2D* getClearcoatTexture() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_CLEARCOAT
                ).ptr()
            );
        }

        void setClearcoatTexture(sunaba::core::Texture2D* texture) {
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

        sunaba::core::Texture2D* getDetailAlbedo() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_ALBEDO
                ).ptr()
            );
        }

        void setDetailAlbedo(sunaba::core::Texture2D* texture) {
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

        sunaba::core::Texture2D* getDetailMask() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_MASK
                ).ptr()
            );
        }

        void setDetailMask(sunaba::core::Texture2D* texture) {
            material->set_texture(
                GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_MASK,
                texture->getTexture2D()
            );
        }

        sunaba::core::Texture2D* getDetailNormal() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_DETAIL_NORMAL
                ).ptr()
            );
        }

        void setDetailNormal(sunaba::core::Texture2D* texture) {
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

        bool getDisableRecieveShadows() {
            return material->get_flag(GodotBaseMaterial3D::FLAG_DONT_RECEIVE_SHADOWS);
        }

        void setDisableRecieveShadows(bool enable) {
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

        int getdinstanceFadeMode() {
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

        sunaba::core::Texture2D* getEmissionTexture() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_EMISSION
                ).ptr()
            );
        }

        void setEmissionTexture(sunaba::core::Texture2D* texture) {
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

        sunaba::core::Texture2D* getHeightmapTexture() {
            return new sunaba::core::Texture2D(
                material->get_texture(
                    GodotBaseMaterial3D::TextureParam::TEXTURE_HEIGHTMAP
                ).ptr()
            );
        }

        void setHeightmapTexture(sunaba::core::Texture2D* texture) {
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

        float getMetalicSpecular() {
            return material->get_specular();
        }

        void setMetalicSpecular(float value) {
            material->set_specular(value);
        }


    };
}

#endif // BASE_MATERIAL3D_H