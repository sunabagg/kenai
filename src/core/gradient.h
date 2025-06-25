#ifndef GRADIENT_H
#define GRADIENT_H

#include <godot_cpp/classes/gradient.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotGradient godot::Gradient

#include "resource.h"
#include "convert_godot_lua.h"

using namespace godot;

namespace lucidware::core {
    void bindGradient(sol::state_view& lua);

    class Gradient : public lucidware::core::Resource {
    private:
        GodotGradient* gradient;
    public:
        Gradient(GodotGradient* g) {
            setGradient(g);
        }

        Gradient() {
            setGradient(memnew(GodotGradient));
        }

        GodotGradient* getGradient() const {
            return gradient;
        }

        void setGradient(GodotGradient* g) {
            gradient = g;
            gradient->reference();
            setResource(g);
        }

        std::vector<Color> getColors() {
            std::vector<Color> colors;
            auto c = gradient->get_colors();
            for (auto i = 0; i < c.size(); i++) {
                colors.push_back(c[i]);
            }
            return colors;
        }

        void setColors(const std::vector<Color>& colors) {
            PackedColorArray c;
            for (auto i = 0; i < colors.size(); i++) {
                c.push_back(colors[i]);
            }
            gradient->set_colors(c);
        }

        int getInterpolationColorSpace() {
            return gradient->get_interpolation_color_space();
        }

        void setInterpolationColorSpace(int color_space) {
            gradient->set_interpolation_color_space(static_cast<GodotGradient::ColorSpace>(color_space));
        }

        int getInterpolationMode() {
            return gradient->get_interpolation_mode();
        }

        void setInterpolationMode(int mode) {
            gradient->set_interpolation_mode(static_cast<GodotGradient::InterpolationMode>(mode));
        }

        std::vector<float> getOffsets() {
            std::vector<float> offsets;
            auto o = gradient->get_offsets();
            for (auto i = 0; i < o.size(); i++) {
                offsets.push_back(o[i]);
            }
            return offsets;
        }

        void setOffsets(const std::vector<float>& offsets) {
            PackedFloat32Array o;
            for (auto i = 0; i < offsets.size(); i++) {
                o.push_back(offsets[i]);
            }
            gradient->set_offsets(o);
        }

        void addPoint(float offset, const Color& color) {
            gradient->add_point(offset, color);
        }

        Color getColor(float point) {
            return gradient->get_color(point);
        }

        float getOffset(int point) {
            return gradient->get_offset(point);
        }

        int getPointCount() {
            return gradient->get_point_count();
        }

        void removePoint(int point) {
            gradient->remove_point(point);
        }

        void reverse() {
            gradient->reverse();
        }

        Color sample(float offset) {
            return gradient->sample(offset);
        }

        void setColor(float offset, const Color& color) {
            gradient->set_color(offset, color);
        }

        void setOffset(int point, float offset) {
            gradient->set_offset(point, offset);
        }
    };
}

#endif