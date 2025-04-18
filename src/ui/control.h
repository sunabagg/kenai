#ifndef CONTROL_H
#define CONTROL_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ControlNode godot::Control

#include "../core/canvas_item.h"

namespace sunaba::ui {
    void bindControl(sol::state &lua);

    class Control;

    class ControlProxy : public ControlNode, public CanvasItemProxy {
        public:
            sunaba::ui::Control* control_element = nullptr;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };
}

#endif // CONTROL_H