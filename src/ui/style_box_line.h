#ifndef STYLE_BOX_LINE_H
#define STYLE_BOX_LINE_H

#include <godot_cpp/classes/style_box_line.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotStyleBoxLine godot::StyleBoxLine

#include "style_box.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindStyleBoxLine(sol::state_view& lua);

    class StyleBoxLine : public StyleBox {
    private:
        GodotStyleBoxLine* p_style_box_line;
    public:
        StyleBoxLine() {
            setStyleBox(memnew(GodotStyleBoxLine));
        }

        StyleBoxLine(GodotStyleBoxLine* _p_style_box_line) {
            setStyleBox(_p_style_box_line);
        }

        GodotStyleBoxLine* getStyleBoxLine() {
            return p_style_box_line;
        }

        void setStyleBoxLine(GodotStyleBoxLine* p_style_box_line) {
            this->p_style_box_line = p_style_box_line;
            p_style_box_line->reference();
            setStyleBox(p_style_box_line);
        }

        Color getColor() {
            return p_style_box_line->get_color();
        }

        void setColor(Color color) {
            p_style_box_line->set_color(color);
        }

        float getGrowBegin() {
            return p_style_box_line->get_grow_begin();
        }

        void setGrowBegin(float grow_begin) {
            p_style_box_line->set_grow_begin(grow_begin);
        }

        float getGrowEnd() {
            return p_style_box_line->get_grow_end();
        }

        void setGrowEnd(float grow_end) {
            p_style_box_line->set_grow_end(grow_end);
        }

        int getThickness() {
            return p_style_box_line->get_thickness();
        }

        void setThickness(int thickness) {
            p_style_box_line->set_thickness(thickness);
        }

        bool isVertical() {
            return p_style_box_line->is_vertical();
        }

        void setVertical(bool vertical) {
            p_style_box_line->set_vertical(vertical);
        }
    };
}

#endif // STYLE_BOX_LINE_H