#ifndef STYLE_BOX_FLAT_H
#define STYLE_BOX_FLAT_H

#include <godot_cpp/classes/style_box_flat.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotStyleBoxFlat godot::StyleBoxFlat

#include "style_box.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindStyleBoxFlat(sol::state_view &lua);

    class StyleBoxFlat : public StyleBox {
    private:
        GodotStyleBoxFlat* p_style_box_flat;
    public:
        StyleBoxFlat() {
            setStyleBox(memnew(GodotStyleBoxFlat));
        }

        StyleBoxFlat(GodotStyleBoxFlat* _p_style_box_flat) {
            setStyleBox(_p_style_box_flat);
        }

        GodotStyleBoxFlat* getStyleBoxFlat() {
            return p_style_box_flat;
        }

        void setStyleBoxFlat(GodotStyleBoxFlat* p_style_box_flat) {
            this->p_style_box_flat = p_style_box_flat;
            p_style_box_flat->reference();
            setStyleBox(p_style_box_flat);
        }

        bool getAntiAliasing() {
            return p_style_box_flat->is_anti_aliased();
        }

        void setAntiAliasing(bool anti_aliasing) {
            p_style_box_flat->set_anti_aliased(anti_aliasing);
        }

        float getAntiAliasingSize() {
            return p_style_box_flat->get_aa_size();
        }

        void setAntiAliasingSize(float anti_aliasing_size) {
            p_style_box_flat->set_aa_size(anti_aliasing_size);
        }

        Color getBgColor() {
            return p_style_box_flat->get_bg_color();
        }

        void setBgColor(Color bg_color) {
            p_style_box_flat->set_bg_color(bg_color);
        }

        bool getBorderBlend() {
            return p_style_box_flat->get_border_blend();
        }

        void setBorderBlend(bool border_blend) {
            p_style_box_flat->set_border_blend(border_blend);
        }

        Color getBorderColor() {
            return p_style_box_flat->get_border_color();
        }

        void setBorderColor(Color border_color) {
            p_style_box_flat->set_border_color(border_color);
        }

        int getBorderWidthBottom() {
            return p_style_box_flat->get_border_width(SIDE_BOTTOM);
        }

        void setBorderWidthBottom(int border_width_bottom) {
            p_style_box_flat->set_border_width(SIDE_BOTTOM, border_width_bottom);
        }

        int getBorderWidthLeft() {
            return p_style_box_flat->get_border_width(SIDE_LEFT);
        }

        void setBorderWidthLeft(int border_width_left) {
            p_style_box_flat->set_border_width(SIDE_LEFT, border_width_left);
        }

        int getBorderWidthRight() {
            return p_style_box_flat->get_border_width(SIDE_RIGHT);
        }

        void setBorderWidthRight(int border_width_right) {
            p_style_box_flat->set_border_width(SIDE_RIGHT, border_width_right);
        }

        int getBorderWidthTop() {
            return p_style_box_flat->get_border_width(SIDE_TOP);
        }

        void setBorderWidthTop(int border_width_top) {
            p_style_box_flat->set_border_width(SIDE_TOP, border_width_top);
        }

        int getCornerDetail() {
            return p_style_box_flat->get_corner_detail();
        }

        void setCornerDetail(int corner_detail) {
            p_style_box_flat->set_corner_detail(corner_detail);
        }

        int getCornerRadiusBottomLeft() {
            return p_style_box_flat->get_corner_radius(CORNER_BOTTOM_LEFT);
        }

        void setCornerRadiusBottomLeft(int corner_radius_bottom_left) {
            p_style_box_flat->set_corner_radius(CORNER_BOTTOM_LEFT, corner_radius_bottom_left);
        }

        int getCornerRadiusBottomRight() {
            return p_style_box_flat->get_corner_radius(CORNER_BOTTOM_RIGHT);
        }

        void setCornerRadiusBottomRight(int corner_radius_bottom_right) {
            p_style_box_flat->set_corner_radius(CORNER_BOTTOM_RIGHT, corner_radius_bottom_right);
        }

        int getCornerRadiusTopLeft() {
            return p_style_box_flat->get_corner_radius(CORNER_TOP_LEFT);
        }

        void setCornerRadiusTopLeft(int corner_radius_top_left) {
            p_style_box_flat->set_corner_radius(CORNER_TOP_LEFT, corner_radius_top_left);
        }

        int getCornerRadiusTopRight() {
            return p_style_box_flat->get_corner_radius(CORNER_TOP_RIGHT);
        }

        void setCornerRadiusTopRight(int corner_radius_top_right) {
            p_style_box_flat->set_corner_radius(CORNER_TOP_RIGHT, corner_radius_top_right);
        }

        bool getDrawCenter() {
            return p_style_box_flat->is_draw_center_enabled();
        }

        void setDrawCenter(bool draw_center) {
            p_style_box_flat->set_draw_center(draw_center);
        }

        float getExpandMarginBottom() {
            return p_style_box_flat->get_expand_margin(SIDE_BOTTOM);
        }

        void setExpandMarginBottom(float expand_margin_bottom) {
            p_style_box_flat->set_expand_margin(SIDE_BOTTOM, expand_margin_bottom);
        }

        float getExpandMarginLeft() {
            return p_style_box_flat->get_expand_margin(SIDE_LEFT);
        }

        void setExpandMarginLeft(float expand_margin_left) {
            p_style_box_flat->set_expand_margin(SIDE_LEFT, expand_margin_left);
        }

        float getExpandMarginRight() {
            return p_style_box_flat->get_expand_margin(SIDE_RIGHT);
        }

        void setExpandMarginRight(float expand_margin_right) {
            p_style_box_flat->set_expand_margin(SIDE_RIGHT, expand_margin_right);
        }

        float getExpandMarginTop() {
            return p_style_box_flat->get_expand_margin(SIDE_TOP);
        }

        void setExpandMarginTop(float expand_margin_top) {
            p_style_box_flat->set_expand_margin(SIDE_TOP, expand_margin_top);
        }

        Color getShadowColor() {
            return p_style_box_flat->get_shadow_color();
        }

        void setShadowColor(Color shadow_color) {
            p_style_box_flat->set_shadow_color(shadow_color);
        }

        Vector2 getShadowOffset() {
            return p_style_box_flat->get_shadow_offset();
        }

        void setShadowOffset(Vector2 shadow_offset) {
            p_style_box_flat->set_shadow_offset(shadow_offset);
        }

        int getShadowSize() {
            return p_style_box_flat->get_shadow_size();
        }

        void setShadowSize(int shadow_size) {
            p_style_box_flat->set_shadow_size(shadow_size);
        }

        Vector2 GetSkew() {
            return p_style_box_flat->get_skew();
        }

        void SetSkew(Vector2 skew) {
            p_style_box_flat->set_skew(skew);
        }

        int getBorderWidth(int side) {
            return p_style_box_flat->get_border_width(static_cast<Side>(side));
        }

        int getBorderWidthMin() {
            return p_style_box_flat->get_border_width_min();
        }

        int getCornerRadius(int corner) {
            return p_style_box_flat->get_corner_radius(static_cast<Corner>(corner));
        }

        float getExpandMargin(int side) {
            return p_style_box_flat->get_expand_margin(static_cast<Side>(side));
        }

        void setBorderWidth(int side, int width) {
            p_style_box_flat->set_border_width(static_cast<Side>(side), width);
        }

        void setBorderWidthAll(int width) {
            p_style_box_flat->set_border_width_all(width);
        }

        void setCornerRadius(int corner, int radius) {
            p_style_box_flat->set_corner_radius(static_cast<Corner>(corner), radius);
        }

        void setCornerRadiusAll(int radius) {
            p_style_box_flat->set_corner_radius_all(radius);
        }

        void setExpandMargin(int margin, float size) {
            p_style_box_flat->set_expand_margin(static_cast<Side>(margin), size);
        }

        void setExpandMarginAll(float size) {
            p_style_box_flat->set_expand_margin_all(size);
        }
    };
}

#endif // STYLE_BOX_FLAT_H