#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <godot_cpp/classes/menu_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define MenuBarNode godot::MenuBar

#include "control.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindMenuBar(sol::state &lua);

    class MenuBar;

    class MenuBarProxy : public MenuBarNode {
        public:
            sunaba::ui::MenuBar* element = nullptr;

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
            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class MenuBar : public sunaba::ui::Control {
        private:
            MenuBarNode* menuBar = nullptr; // Pointer to the MenuBar instance
            void connectMenuBarSignals() {
                // Connect signals specific to MenuBar
            }

        public:
        MenuBar() {
            setMenuBar(memnew(MenuBarProxy));
            onInit();
        }

        MenuBar(MenuBarNode* menuBar) {
            setMenuBar(menuBar);
        }

        MenuBarNode* getMenuBar() {
            return menuBar;
        }

        void setMenuBar(MenuBarNode* menuBar) {
            this->menuBar = menuBar;
            connectMenuBarSignals();
            setControl(menuBar);
        }

        void setMenuBar(MenuBarProxy* menuBar) {
            this->menuBar = menuBar;
            menuBar->element = this;
            connectMenuBarSignals();
            setControl(menuBar);
        }

        bool isFlat() {
            return menuBar->is_flat();
        }

        void setFlat(bool p_enabled) {
            menuBar->set_flat(p_enabled);
        }

        std::string getLanguage() {
            return menuBar->get_language().utf8().get_data();
        }

        void setLanguage(const String &p_language) {
            menuBar->set_language(p_language);
        }

        bool isPreferGlobalMenu() {
            return menuBar->is_prefer_global_menu();
        }

        void setPreferGlobalMenu(bool p_enabled) {
            menuBar->set_prefer_global_menu(p_enabled);
        }
    };
}

#endif // ! MENU_BAR_H