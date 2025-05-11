#ifndef OPTION_BUTTON_H
#define OPTION_BUTTON_H

#include <godot_cpp/classes/option_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define OptionButtonNode godot::OptionButton

#include "button.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindOptionButton(sol::state& lua);

    class OptionButton;

    class OptionButtonProxy : public OptionButtonNode {
        public:
            sunaba::ui::OptionButton* element = nullptr;

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

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;

            void _pressed() override;

            void _toggled(bool p_toggled_on) override;
    };

    class OptionButton : public sunaba::ui::Button {
        private:
            OptionButtonNode* optionButton = nullptr;

            void connectOptionButtonSignals() {
                // Connect signals specific to OptionButton
            }

        public:
            // Constructor with Node* parameter
            OptionButton() {
                setOptionButton(memnew(OptionButtonProxy));
                onInit();
            }

            OptionButton(OptionButtonNode* p_node) {
                setOptionButton(p_node);
            }

            OptionButtonNode* getOptionButton() {
                return optionButton;
            }

            void setOptionButton(OptionButtonNode* optionButton) {
                this->optionButton = optionButton;
                connectOptionButtonSignals();
                setButton(optionButton);
            }

            void setOptionButton(OptionButtonProxy* optionButton) {
                this->optionButton = optionButton;
                optionButton->element = this;
                connectOptionButtonSignals();
                setButton(optionButton);
            }

            int getActionMode() {
                return optionButton->get_action_mode();
            }

            void setActionMode(int mode) {
                optionButton->set_action_mode(static_cast<godot::OptionButton::ActionMode>(mode));
            }

            int getAlignment() {
                return optionButton->get_text_alignment();
            }

            void setAlignment(int alignment) {
                optionButton->set_text_alignment(static_cast<godot::HorizontalAlignment>(alignment));
            }

            bool getAllowReselect() {
                return optionButton->get_allow_reselect();
            }
    };
}

#endif // OPTION_BUTTON_H