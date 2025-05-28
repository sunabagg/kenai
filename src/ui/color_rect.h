#ifndef COLOR_RECT_H
#define COLOR_RECT_H

#include <godot_cpp/classes/color_rect.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ColorRectNode godot::ColorRect

#include "control.h"

using namespace godot;
namespace sunaba::ui {
    void bindColorRect(sol::state &lua);

    class ColorRect;

    class ColorRectProxy : public ColorRectNode {
        public:
            sunaba::ui::ColorRect* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            void _draw() override;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class ColorRect : public Control {
        private:
            ColorRectNode* color_rect = nullptr; // Pointer to the ColorRect instance

        public:
            ColorRect() {
                setColorRect(memnew(ColorRectProxy));
                onInit();
            }

            ColorRect(ColorRectNode* p_node) {
                setColorRect(p_node);
            }

            ColorRectNode* getColorRect() {
                return color_rect;
            }

            void setColorRect(ColorRectNode* p_node) {
                color_rect = p_node;
                setControl(color_rect);
            }

            void setColorRectProxy(ColorRectProxy* p_node) {
                color_rect = p_node;
                p_node->element = this;
                setControl(color_rect);
            }
    }
}