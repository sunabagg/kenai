#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H

#include <godot_cpp/classes/base_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define BaseButtonNode godot::BaseButton

#include "control.h"

#include "../core/stl_function_wrapper.h"
#define StlFunctionWrapper sunaba::core::StlFunctionWrapper

namespace sunaba::ui {
    void bindBaseButton(sol::state &lua);

    class BaseButton;

     class BaseButtonProxy : public BaseButtonNode {
        public:
            sunaba::ui::BaseButton* element = nullptr;

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

            void _pressed() override;

            void _toggled(bool p_toggled_on) override;
    };
}

#endif // BASE_BUTTON_H