#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <godot_cpp/classes/menu_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define MenuButtonNode godot::MenuButton

#include "button.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindMenuButton(sol::state& lua);

    class MenuButtonProxy : public MenuButtonNode {
        public:
            sunaba::ui::MenuButton* element = nullptr;

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

    class MenuButton : public Button {
        private:
            MenuButtonNode* menu_button = nullptr;

            void connectMenuButtonSignals() {

            }

        public:
            MenuButton() {
                setMenuButton(memnew(MenuButtonProxy));
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
    };
} 

#endif // MENU_BUTTON_H