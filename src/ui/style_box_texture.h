#ifndef STYLE_BOX_TEXTURE_H
#define STYLE_BOX_TEXTURE_H

#include <godot_cpp/classes/style_box_texture.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotStyleBoxTexture godot::StyleBoxTexture

#include "style_box.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindStyleBoxTexture(sol::state_view& lua);

    class StyleBoxTexture : public StyleBox {
    private:
        GodotStyleBoxTexture* p_style_box_texture;
    public:
        StyleBoxTexture() {
            setStyleBox(memnew(GodotStyleBoxTexture));
        }

        StyleBoxTexture(GodotStyleBoxTexture* _p_style_box_texture) {
            setStyleBox(_p_style_box_texture);
        }

        GodotStyleBoxTexture* getStyleBoxTexture() {
            return p_style_box_texture;
        }

        void setStyleBoxTexture(GodotStyleBoxTexture* p_style_box_texture) {
            this->p_style_box_texture = p_style_box_texture;
            p_style_box_texture->reference();
            setStyleBox(p_style_box_texture);
        }

        int getAxisStretchHorizontal() {
            return p_style_box_texture->get_h_axis_stretch_mode();
        }

        void setAxisStretchHorizontal(int axis_stretch_horizontal) {
            p_style_box_texture->set_h_axis_stretch_mode(static_cast<GodotStyleBoxTexture::AxisStretchMode>(axis_stretch_horizontal));
        }

        int getAxisStretchVertical() {
            return p_style_box_texture->get_v_axis_stretch_mode();
        }

        void setAxisStretchVertical(int axis_stretch_vertical) {
            p_style_box_texture->set_v_axis_stretch_mode( static_cast<GodotStyleBoxTexture::AxisStretchMode>(axis_stretch_vertical));
        }

        bool isDrawCenter() {
            return p_style_box_texture->is_draw_center_enabled();
        }

        void setDrawCenter(bool draw_center) {
            p_style_box_texture->set_draw_center(draw_center);
        }

        float getExpandMarginBottom() {
            return p_style_box_texture->get_expand_margin(SIDE_BOTTOM);
        }

        void setExpandMarginBottom(float expand_margin_bottom) {
            p_style_box_texture->set_expand_margin(SIDE_BOTTOM, expand_margin_bottom);
        }

        float getExpandMarginLeft() {
            return p_style_box_texture->get_expand_margin(SIDE_LEFT);
        }

        void setExpandMarginLeft(float expand_margin_left) {
            p_style_box_texture->set_expand_margin(SIDE_LEFT, expand_margin_left);
        }

        float getExpandMarginRight() {
            return p_style_box_texture->get_expand_margin(SIDE_RIGHT);
        }

        void setExpandMarginRight(float expand_margin_right) {
            p_style_box_texture->set_expand_margin(SIDE_RIGHT, expand_margin_right);
        }

        float getExpandMarginTop() {
            return p_style_box_texture->get_expand_margin(SIDE_TOP);
        }

        void setExpandMarginTop(float expand_margin_top) {
            p_style_box_texture->set_expand_margin(SIDE_TOP, expand_margin_top);
        }

        Color getModulateColor() {
            return p_style_box_texture->get_modulate();
        }

        void setModulateColor(Color modulate_color) {
            p_style_box_texture->set_modulate(modulate_color);
        }

        Rect2 getRegionRect() {
            return p_style_box_texture->get_region_rect();
        }

        void setRegionRect(Rect2 region_rect) {
            p_style_box_texture->set_region_rect(region_rect);
        }

        lucidware::core::Texture2D* getTexture() {
            return new lucidware::core::Texture2D(p_style_box_texture->get_texture().ptr());
        }

        void setTexture(lucidware::core::Texture2D* texture) {
            p_style_box_texture->set_texture(Ref<GodotTexture2D>(texture->getTexture()));
        }

        float getTextureMarginBottom() {
            return p_style_box_texture->get_texture_margin(SIDE_BOTTOM);
        }

        void setTextureMarginBottom(float textures_margin_bottom) {
            p_style_box_texture->set_texture_margin(SIDE_BOTTOM, textures_margin_bottom);
        }
        
        float getTextureMarginLeft() {
            return p_style_box_texture->get_texture_margin(SIDE_LEFT);
        }

        void setTextureMarginLeft(float textures_margin_left) {
            p_style_box_texture->set_texture_margin(SIDE_LEFT, textures_margin_left);
        }

        float getTextureMarginRight() {
            return p_style_box_texture->get_texture_margin(SIDE_RIGHT);
        }

        void setTextureMarginRight(float textures_margin_right) {
            p_style_box_texture->set_texture_margin(SIDE_RIGHT, textures_margin_right);
        }

        float getTextureMarginTop() {
            return p_style_box_texture->get_texture_margin(SIDE_TOP);
        }

        void setTextureMarginTop(float textures_margin_top) {
            p_style_box_texture->set_texture_margin(SIDE_TOP, textures_margin_top);
        }

        float getExpandMargin(int side) {
            return p_style_box_texture->get_expand_margin(static_cast<Side>(side));
        }

        float getTextureMargin(int side) {
            return p_style_box_texture->get_texture_margin(static_cast<Side>(side));
        }

        void setExpandMargin(int side, float expand_margin) {
            p_style_box_texture->set_expand_margin(static_cast<Side>(side), expand_margin);
        }

        void setExpandMarginAll(float expand_margin) {
            p_style_box_texture->set_expand_margin_all(expand_margin);
        }

        void setTextureMargin(int side, float texture_margin) {
            p_style_box_texture->set_texture_margin(static_cast<Side>(side), texture_margin);
        }

        void setTextureMarginAll(float texture_margin) {
            p_style_box_texture->set_texture_margin_all(texture_margin);
        }
    };
}

#endif // STYLE_BOX_TEXTURE_H