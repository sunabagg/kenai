#ifndef STYLE_BOX_H
#define STYLE_BOX_H

#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotStyleBox godot::StyleBox

#include "../core/resource.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindStyleBox(sol::state &lua);

    class StyleBox : public lucidfx::core::Resource {
    private:
        GodotStyleBox* style_box = nullptr; // Pointer to the StyleBox instance
    public:
        // Constructor with Node* parameter
        StyleBox(GodotStyleBox* p_node) {
            setStyleBox(p_node);
        }
    
        // Constructor with no parameters
        StyleBox() {
            setStyleBox(memnew(GodotStyleBox));
        }

        // Getter for the StyleBox node
        GodotStyleBox* getStyleBox() {
            return style_box;
        }

        // Setter for the StyleBox node
        void setStyleBox(GodotStyleBox* p_node) {
            style_box = p_node;
            setResource(style_box);
        }

        float getContentMarginTop() {
            return style_box->get_content_margin(SIDE_TOP);
        }

        void setContentMarginTop(float margin) {
            style_box->set_content_margin(SIDE_TOP, margin);
        }

        float getContentMarginBottom() {
            return style_box->get_content_margin(SIDE_BOTTOM);
        }

        void setContentMarginBottom(float margin) {
            style_box->set_content_margin(SIDE_BOTTOM, margin);
        }

        float getContentMarginLeft() {
            return style_box->get_content_margin(SIDE_LEFT);
        }

        void setContentMarginLeft(float margin) {
            style_box->set_content_margin(SIDE_LEFT, margin);
        }

        float getContentMarginRight() {
            return style_box->get_content_margin(SIDE_RIGHT);
        }

        void setContentMarginRight(float margin) {
            style_box->set_content_margin(SIDE_RIGHT, margin);
        }

        float getContentMargin(int margin) {
            return style_box->get_content_margin(static_cast<Side>(margin));
        }

        float getMargin(int margin) {
            return style_box->get_margin(static_cast<Side>(margin));
        }

        Vector2 getMinimumSize() {
            return style_box->get_minimum_size();
        }

        Vector2 getOffset() {
            return style_box->get_offset();
        }

        void setContentMargin(int margin, float value) {
            style_box->set_content_margin(static_cast<Side>(margin), value);
        }

        void setContentMarginAll(float offset) {
            style_box->set_content_margin_all(offset);
        }
    };
}

#endif // STYLE_BOX_H