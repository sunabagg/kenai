#ifndef POPUP_MENU_H
#define POPUP_MENU_H

#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define PopupMenuNode godot::PopupMenu

#include "popup.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindPopupMenu(sol::state& lua);

    class PopupMenu;

    class PopupMenuProxy : public PopupMenuNode {
    public:
        sunaba::desktop::PopupMenu* element = nullptr;

        void onInit() {
            // Initialize the NodeProxy instance
        }

        void _enter_tree() override;
        void _exit_tree() override;
        void _ready() override;
        void _process(double delta) override;
        void _physics_process(double delta) override;
        void _input(const Ref<InputEvent>& event) override;
        void _unhandled_input(const Ref<InputEvent>& event) override;
        void _unhandled_key_input(const Ref<InputEvent>& event) override;
        void _shortcut_input(const Ref<InputEvent>& event) override;

        Vector2 _get_contents_minimum_size() const override;
    };

    class PopupMenu : public Popup {
        private:
            PopupMenuNode* popup_menu = nullptr; // Pointer to the PopupMenu instance
            void connectPopupMenuSignals() {
                // Connect signals specific to PopupMenu
            }
        public:
            PopupMenu() {
                setPopup(memnew(PopupMenuProxy));
                onInit();
            }

            PopupMenu(PopupMenuNode* popup_menu) {
                setPopup(popup_menu);
                onInit();
            }

            PopupMenuNode* getPopupMenu() const {
                return popup_menu;
            }

            void setPopupMenu(PopupMenuNode* popup_menu) {
                this->popup_menu = popup_menu;
                connectPopupMenuSignals();
                setPopup(popup_menu);
            }

            void setPopupMenu(PopupMenuProxy* popup_menu) {
                this->popup_menu = popup_menu;
                popup_menu->element = this;
                connectPopupMenuSignals();
                setPopup(popup_menu);
            }

            bool getAllowSearch() const {
                return popup_menu->get_allow_search();
            }

            void setAllowSearch(bool allow_search) {
                popup_menu->set_allow_search(allow_search);
            }

            bool getHideOnCheckableItemSelection() const {
                return popup_menu->is_hide_on_checkable_item_selection();
            }

            void setHideOnCheckableItemSelection(bool hide_on_checkable_item_selection) {
                popup_menu->set_hide_on_checkable_item_selection(hide_on_checkable_item_selection);
            }

            bool getHideOnItemSelection() const {
                return popup_menu->is_hide_on_item_selection();
            }

            void setHideOnItemSelection(bool hide_on_item_selection) {
                popup_menu->set_hide_on_item_selection(hide_on_item_selection);
            }

            bool getHideOnStateItemSelection() const {
                return popup_menu->is_hide_on_state_item_selection();
            }

            void setHideOnStateItemSelection(bool hide_on_state_item_selection) {
                popup_menu->set_hide_on_state_item_selection(hide_on_state_item_selection);
            }

            int getItemCount() const {
                return popup_menu->get_item_count();
            }
    };
}

#endif