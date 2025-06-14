#ifndef CHECK_BOX_H
#define CHECK_BOX_H

#include <godot_cpp/classes/check_box.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define CheckBoxNode godot::CheckBox

#include "button.h"

namespace sunaba::ui {
    void bindCheckBox(sol::state& lua);
    
    class CheckBox;

    class CheckBoxProxy : public CheckBoxNode {
        GDCLASS(CheckBoxProxy, CheckBoxNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to CheckBoxProxy
            }
        public:
            sunaba::ui::CheckBox* element = nullptr;

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

    class CheckBox : public sunaba::ui::Button {
        private:
            CheckBoxNode* check_box = nullptr;

        public:
            // Constructor with Node* parameter
            CheckBox(CheckBoxNode* p_node) {
                setCheckBox(p_node);
            }

            // Constructor with no parameters
            CheckBox() {
                setCheckBox(memnew(CheckBoxNode));
                onInit();
            }

            // Getter for the CheckBox node
            CheckBoxNode* getCheckBox() {
                return check_box;
            }

            // Setter for the CheckBox node
            void setCheckBox(CheckBoxNode* p_node) {
                check_box = p_node;
                setBaseButton(check_box);
            }

            void setCheckBox(CheckBoxProxy* p_node) {
                check_box = p_node;
                p_node->element = this;
                setBaseButton(p_node);
            }

            int getAlignment() {
                return check_box->get_text_alignment();
            }

            void setAlignment(int alignment) {
                check_box->set_text_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            bool isToggleMode() {
                return check_box->is_toggle_mode();
            }

            void setToggleMode(bool enabled) {
                check_box->set_toggle_mode(enabled);
            }
    };
}

#endif // CHECK_BOX_H