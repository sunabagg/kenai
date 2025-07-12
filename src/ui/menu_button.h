#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <godot_cpp/classes/menu_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define MenuButtonNode godot::MenuButton

#include "button.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "../desktop/popup_menu.h"

using namespace godot;
using namespace kenai::core;

namespace kenai::ui {
    void bindMenuButton(sol::state& lua);

    class MenuButton;

    class MenuButtonProxy : public MenuButtonNode {
        GDCLASS(MenuButtonProxy, MenuButtonNode)
        protected:
            static void _bind_methods() {
                // Binding methods for MenuButtonProxy
            }
        public:
            kenai::ui::MenuButton* element = nullptr;

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

    class MenuButtonSignalWrapper : public Object {
        GDCLASS(MenuButtonSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            kenai::ui::MenuButton* element = nullptr;

            MenuButtonSignalWrapper() = default;
            ~MenuButtonSignalWrapper() = default;

            void about_to_popup();
    };

    class MenuButton : public Button {
        private:
            MenuButtonNode* menu_button = nullptr;

            MenuButtonSignalWrapper* menu_button_signal_wrapper = nullptr;
            void connectMenuButtonSignals() {
                // Connect signals specific to MenuButton
                if (this->menu_button_signal_wrapper == nullptr) {
                    this->menu_button_signal_wrapper = memnew(MenuButtonSignalWrapper);
                    this->menu_button_signal_wrapper->element = this;
                }
                this->menu_button->connect("about_to_popup", Callable(this->menu_button_signal_wrapper, "about_to_popup"));
            }
        public:
            MenuButton() {
                setMenuButton(memnew(MenuButtonNode));
                onInit();
            }

            // Constructor with Node* parameter
            MenuButton(MenuButtonNode* p_node) {
                setMenuButton(p_node);
            }

            MenuButtonNode* getMenuButton() {
                return menu_button;
            }

            // Constructor with Node* parameter
            void setMenuButton(MenuButtonNode* p_node) {
                menu_button = p_node;
                connectMenuButtonSignals();
                setButton(menu_button);
            }

            void setMenuButton(MenuButtonProxy* p_node) {
                menu_button = p_node;
                p_node->element = this;
                connectMenuButtonSignals();
                setButton(menu_button);
            }

            int getActionMode() {
                return menu_button->get_action_mode();
            }

            void setActionMode(int mode) {
                menu_button->set_action_mode(static_cast<godot::MenuButton::ActionMode>(mode));
            }

            bool getFlat() {
                return menu_button->is_flat();
            }

            void setFlat(bool enabled) {
                menu_button->set_flat(enabled);
            }

            int getFocusMode() {
                return menu_button->get_focus_mode();
            }

            void setFocusMode(int mode) {
                menu_button->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            int getItemCount() const {
                return menu_button->get_item_count();
            }

            void setItemCount(int32_t p_count) {
                menu_button->set_item_count(p_count);
            }

            bool isSwitchOnHover() {
                return menu_button->is_switch_on_hover();
            }

            void setSwitchOnHover(bool enabled) {
                menu_button->set_switch_on_hover(enabled);
            }

            bool isToggleMode() {
                return menu_button->is_toggle_mode();
            }

            void setToggleMode(bool enabled) {
                menu_button->set_toggle_mode(enabled);
            }

            Event* aboutToPopupEvent = new Event();
            Event* getAboutToPopupEvent() {
                return aboutToPopupEvent;
            }
            void setAboutToPopupEvent(Event* event) {
                aboutToPopupEvent = event;
            }

            kenai::desktop::PopupMenu* getPopup() {
                return new kenai::desktop::PopupMenu(menu_button->get_popup());
            }

            void setDisableShortcuts(bool p_disabled) {
                menu_button->set_disable_shortcuts(p_disabled);
            }

            void showPopup() {
                menu_button->show_popup();
            }

            void onFree() override {
                if (menu_button_signal_wrapper) {
                    memdelete(menu_button_signal_wrapper);
                    menu_button_signal_wrapper = nullptr;
                }
                Button::onFree();
            }
    };
} 

#endif // MENU_BUTTON_H