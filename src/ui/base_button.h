#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H

#include <godot_cpp/classes/base_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define BaseButtonNode godot::BaseButton

#include "control.h"
#include "../input/shortcut.h"
#include "../core/event.h"

#include "../core/stl_function_wrapper.h"
using namespace sunaba::core;

namespace sunaba::ui {
    void bindBaseButton(sol::state &lua);

    class BaseButton;

    class ButtonGroup;

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

    class BaseButtonSignalWrapper : public Object {
        GDCLASS(BaseButtonSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            sunaba::ui::BaseButton* element = nullptr;

            BaseButtonSignalWrapper() = default;
            ~BaseButtonSignalWrapper() = default;

            void pressed();
            void toggled(bool p_toggled_on);
            void button_down();
            void button_up();
    };

    class BaseButton : public sunaba::ui::Control {
        private:
            BaseButtonNode* base_button = nullptr;

            BaseButtonSignalWrapper* base_button_signal_wrapper = nullptr;
            void connectBaseButtonSignals() {
                if (this->base_button_signal_wrapper == nullptr) {
                    this->base_button_signal_wrapper = memnew(BaseButtonSignalWrapper);
                    this->base_button_signal_wrapper->element = this;
                }

                this->base_button->connect("pressed", Callable(this->base_button_signal_wrapper, "pressed"));
                this->base_button->connect("toggled", Callable(this->base_button_signal_wrapper, "toggled"));
                this->base_button->connect("button_down", Callable(this->base_button_signal_wrapper, "button_down"));
                this->base_button->connect("button_up", Callable(this->base_button_signal_wrapper, "button_up"));
            }
        
        public:
            // Constructor with Node* parameter
            BaseButton(BaseButtonNode* p_node) {
                setBaseButton(p_node);
            }

            BaseButton(BaseButtonProxy* p_node) {
                setBaseButton(p_node);
            }

            // Constructor with no parameters
            BaseButton() {
                setBaseButton(memnew(BaseButtonProxy));
                onInit();
            }

            // Getter for the BaseButton node
            BaseButtonNode* getBaseButton() {
                return base_button;
            }

            // Setter for the BaseButton node
            void setBaseButton(BaseButtonNode* p_node) {
                base_button = p_node;
                connectBaseButtonSignals();
                setCanvasItem(base_button);
            }

            void setBaseButton(BaseButtonProxy* p_node) {
                base_button = p_node;
                p_node->element = this;
                connectBaseButtonSignals();
                setCanvasItem(p_node);
            }

            int getActionMode() {
                return base_button->get_action_mode();
            }

            void setActionMode(int mode) {
                base_button->set_action_mode(static_cast<godot::BaseButton::ActionMode>(mode));
            }

            ButtonGroup* getButtonGroup();
            void setButtonGroup(ButtonGroup* group);

            int getButtonMask() {
                return base_button->get_button_mask();
            }

            void setButtonMask(int mask) {
                base_button->set_button_mask(static_cast<godot::BitField<godot::MouseButtonMask>>(mask));
            }

            bool getButtonPressed() {
                return base_button->is_pressed();
            }

            void setButtonPressed(bool pressed) {
                base_button->set_pressed(pressed);
            }

            bool getDisabled() {
                return base_button->is_disabled();
            }

            void setDisabled(bool disabled) {
                base_button->set_disabled(disabled);
            }

            int getFocusMode() {
                return base_button->get_focus_mode();
            }

            void setFocusMode(int mode) {
                base_button->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            bool getKeepPressedOutside() {
                return base_button->is_keep_pressed_outside();
            }
            
            void setKeepPressedOutside(bool enabled) {
                base_button->set_keep_pressed_outside(enabled);
            }

            sunaba::input::Shortcut* getShortcut() {
                return new sunaba::input::Shortcut(base_button->get_shortcut().ptr());
            }

            void setShortcut(sunaba::input::Shortcut* shortcut) {
                base_button->set_shortcut(shortcut->getShortcut());
            }

            bool getShortcutFeedback() {
                return base_button->is_shortcut_feedback();
            }

            void setShortcutFeedback(bool enabled) {
                base_button->set_shortcut_feedback(enabled);
            }

            bool getToggleMode() {
                return base_button->is_toggle_mode();
            }

            void setToggleMode(bool enabled) {
                base_button->set_toggle_mode(enabled);
            }

            Event* buttonDown;
            Event* getButtonDown() {
                return buttonDown;
            }
            void setButtonDown(Event* event) {
                buttonDown = event;
            }
            Event* buttonUp;
            Event* getButtonUp() {
                return buttonUp;
            }
            void setButtonUp(Event* event) {
                buttonUp = event;
            }
            Event* pressedEvent;
            Event* getPressedEvent() {
                return pressedEvent;
            }
            void setPressedEvent(Event* event) {
                pressedEvent = event;
            }
            Event* toggledEvent;
            Event* getToggledEvent() {
                return toggledEvent;
            }
            void setToggledEvent(Event* event) {
                toggledEvent = event;
            }

            int getDrawMode() {
                return base_button->get_draw_mode();
            }

            bool isHovered() {
                return base_button->is_hovered();
            }

            void setPressedNoEvent(bool pressed) {
                base_button->set_pressed_no_signal(pressed);
            }

            void pressed() {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["pressed"].get<sol::function>();
                    if (func) {
                        func(scriptInstance);
                    }
                }
            }

            void toggled(bool toggled) {
                if (scriptInstance != sol::lua_nil) {
                    auto func = scriptInstance["toggled"].get<sol::function>();
                    if (func) {
                        func(scriptInstance, toggled);
                    }
                }
            }

            void onFree() override {
                if (base_button_signal_wrapper) {
                    base_button_signal_wrapper->element = nullptr;
                    memdelete(base_button_signal_wrapper);
                    base_button_signal_wrapper = nullptr;
                }
                Control::onFree();
            }
        };
}

#endif // BASE_BUTTON_H