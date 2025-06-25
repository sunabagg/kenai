#ifndef CHECK_BUTTON_H
#define CHECK_BUTTON_H

#include <godot_cpp/classes/check_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define CheckButtonNode godot::CheckButton

#include "button.h"


namespace lucidware::ui {
    void bindCheckButton(sol::state& lua);
    
    class CheckButton;

    class CheckButtonProxy : public CheckButtonNode {
        GDCLASS(CheckButtonProxy, CheckButtonNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to CheckButtonProxy
            }
        public:
            lucidware::ui::CheckButton* element = nullptr;

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

    class CheckButton : public lucidware::ui::Button {
        private:
            CheckButtonNode* check_button = nullptr;

        public:
            // Constructor with Node* parameter
            CheckButton(CheckButtonNode* p_node) {
                setCheckButton(p_node);
            }

            // Constructor with no parameters
            CheckButton() {
                setCheckButton(memnew(CheckButtonNode));
                onInit();
            }

            // Getter for the CheckButton node
            CheckButtonNode* getCheckButton() {
                return check_button;
            }

            // Setter for the CheckButton node
            void setCheckButton(CheckButtonNode* p_node) {
                check_button = p_node;
                setBaseButton(check_button);
            }

            void setCheckButton(CheckButtonProxy* p_node) {
                check_button = p_node;
                p_node->element = this;
                setBaseButton(p_node);
            }

            int getAlignment() {
                return check_button->get_text_alignment();
            }

            void setAlignment(int alignment) {
                check_button->set_text_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            bool getToggleMode() {
                return check_button->is_toggle_mode();
            }

            void setToggleMode(bool enabled) {
                check_button->set_toggle_mode(enabled);
            }
    };
}

#endif