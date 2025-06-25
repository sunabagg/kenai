#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <godot_cpp/classes/menu_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define MenuBarNode godot::MenuBar

#include "control.h"
#include "../desktop/popup_menu.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindMenuBar(sol::state &lua);

    class MenuBar;

    class MenuBarProxy : public MenuBarNode {
        GDCLASS(MenuBarProxy, MenuBarNode)
        protected:
            static void _bind_methods() {
                // Bind methods specific to MenuBarProxy
            }
        public:
            lucidfx::ui::MenuBar* element = nullptr;

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

    class MenuBar : public lucidfx::ui::Control {
        private:
            MenuBarNode* menuBar = nullptr; // Pointer to the MenuBar instance
            void connectMenuBarSignals() {
                // Connect signals specific to MenuBar
            }

        public:
        MenuBar() {
            setMenuBar(memnew(MenuBarNode));
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

        int getStartIndex() {
            return menuBar->get_start_index();
        }

        void setStartIndex(int32_t p_enabled) {
            menuBar->set_start_index(p_enabled);
        }

        bool isSwitchOnHover() {
            return menuBar->is_switch_on_hover();
        }

        void setSwitchOnHover(bool p_enable) {
            menuBar->set_switch_on_hover(p_enable);
        }

        int getTextDirection() {
            return menuBar->get_text_direction();
        }

        void setTextDirection(godot::Control::TextDirection p_direction) {
            menuBar->set_text_direction(p_direction);
        }

        int getMenuCount() {
            return menuBar->get_menu_count();
        }

        lucidfx::desktop::PopupMenu* getMenuPopup(int32_t p_menu) {
            return new lucidfx::desktop::PopupMenu(menuBar->get_menu_popup(p_menu));
        }

        std::string getMenuTitle(int32_t p_menu) {
            return menuBar->get_menu_title(p_menu).utf8().get_data();
        }

        std::string getMenuTooltip(int32_t p_menu) {
            return menuBar->get_menu_tooltip(p_menu).utf8().get_data();
        }

        bool isMenuDisabled(int32_t p_menu) {
            return menuBar->is_menu_disabled(p_menu);
        }

        bool isMenuHidden(int32_t p_menu) {
            return menuBar->is_menu_hidden(p_menu);
        }

        bool isNativeMenu() {
            return menuBar->is_native_menu();
        }

        void setDisableShortcuts(bool p_disabled) {
            menuBar->set_disable_shortcuts(p_disabled);
        }

        void setMenuDisabled(int32_t p_menu, bool p_disabled) {
            menuBar->set_menu_disabled(p_menu, p_disabled);
        }

        void setMenuHidden(int32_t p_menu, bool p_hidden) {
            menuBar->set_menu_hidden(p_menu, p_hidden);
        }

        void setMenuTitle(int32_t p_menu, const std::string &p_title) {
            menuBar->set_menu_title(p_menu, p_title.c_str());
        }

        void setMenuTooltip(int32_t p_menu, const std::string &p_tooltip) {
            menuBar->set_menu_tooltip(p_menu, p_tooltip.c_str());
        }
    };
}

#endif // ! MENU_BAR_H