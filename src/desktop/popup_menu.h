#ifndef POPUP_MENU_H
#define POPUP_MENU_H

#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define PopupMenuNode godot::PopupMenu

#include "popup.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "../input/input_event.h"
#include "../input/shortcut.h"
#include "../core/texture2d.h"

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

            void setItemCount(int count) {
                popup_menu->set_item_count(count);
            }

            bool getPreferNativeMenu() const {
                return popup_menu->is_prefer_native_menu();
            }

            void setPreferNativeMenu(bool prefer_native_menu) {
                popup_menu->set_prefer_native_menu(prefer_native_menu);
            }

            float getSubmenuPopupDelay() const {
                return popup_menu->get_submenu_popup_delay();
            }

            void setSubmenuPopupDelay(float seconds) {
                popup_menu->set_submenu_popup_delay(seconds);
            }

            int getSystemMenuId() const {
                return popup_menu->get_system_menu();
            }

            void setSystemMenuId(int id) {
                popup_menu->set_system_menu(static_cast<NativeMenu::SystemMenus>(id));
            }

            bool getTransparent() {
                return popup_menu->get_flag(godot::Popup::Flags::FLAG_TRANSPARENT);
            }

            void setTransparent(bool transparent) {
                popup_menu->set_flag(godot::Popup::Flags::FLAG_TRANSPARENT, transparent);
            }

            bool getTransparentBg() {
                return popup_menu->has_transparent_background();
            }

            void setTransparentBg(bool transparent_bg) {
                popup_menu->set_transparent_background(transparent_bg);
            }

            Event* ifFocusedEvent;
            Event* getIfFocusedEvent() {
                return ifFocusedEvent;
            }
            void setIfFocusedEvent(Event* event) {
                ifFocusedEvent = event;
            }
            Event* idPressedEvent;
            Event* getIdPressedEvent() {
                return idPressedEvent;
            }
            void setIdPressedEvent(Event* event) {
                idPressedEvent = event;
            }
            Event* indexPressedEvent;
            Event* getIndexPressedEvent() {
                return indexPressedEvent;
            }
            void setIndexPressedEvent(Event* event) {
                indexPressedEvent = event;
            }
            Event* menuChangedEvent;
            Event* getMenuChangedEvent() {
                return menuChangedEvent;
            }
            void setMenuChangedEvent(Event* event) {
                menuChangedEvent = event;
            }

            bool activateItemByEvent(sunaba::input::InputEvent* event, bool forGlobalOnly = false) {
                return popup_menu->activate_item_by_event(event->getInputEvent(), forGlobalOnly);
            }

            void addCheckItem(const std::string& label, int id = -1, int accel = 0) {
                popup_menu->add_check_item(label.c_str(), id, static_cast<godot::Key>(accel));
            }

            void addCheckShortcut(sunaba::input::Shortcut* shortcut, int id  = -1, bool global = false) {
                popup_menu->add_check_shortcut(shortcut->getShortcut(), id, global);
            }

            void addIconCheckItem(sunaba::core::Texture2D* texture, std::string label, int id = -1, int accel = 0) {
                popup_menu->add_icon_check_item(texture->getTexture2D(), label.c_str(), id, static_cast<godot::Key>(accel));
            }

            void addIconCheckShortcut(sunaba::core::Texture2D* texture, sunaba::input::Shortcut* shortcut, int id = -1, bool global = false) {
                popup_menu->add_icon_check_shortcut(texture->getTexture2D(), shortcut->getShortcut(), id, global);
            }

            void addIconItem(sunaba::core::Texture2D* texture, std::string label, int id = -1, int accel = 0) {
                popup_menu->add_icon_item(texture->getTexture2D(), label.c_str(), id, static_cast<godot::Key>(accel));
            } 

            void addIconRadioCheckItem(sunaba::core::Texture2D* texture, std::string label, int id = -1, int accel = 0) {
                popup_menu->add_icon_radio_check_item(texture->getTexture2D(), label.c_str(), id, static_cast<godot::Key>(accel));
            }

            void addIconRadioCheckShortcut(sunaba::core::Texture2D* texture, sunaba::input::Shortcut* shortcut, int id = -1, bool global = false) {
                popup_menu->add_icon_radio_check_shortcut(texture->getTexture2D(), shortcut->getShortcut(), id, global);
            }

            void addIconShortcut(sunaba::core::Texture2D* texture, sunaba::input::Shortcut* shortcut, int id = -1, bool global = false, bool allowEcho = false) {
                popup_menu->add_icon_shortcut(texture->getTexture2D(), shortcut->getShortcut(), id, global, allowEcho);
            }

            void addItem(const std::string& label, int id = -1, int accel = 0) {
                popup_menu->add_item(label.c_str(), id, static_cast<godot::Key>(accel));
            }

            void addMultistateItem(const std::string& label, int maxStates, int defaultState = 0, int id = -1, int accel = 0) {
                popup_menu->add_multistate_item(label.c_str(), maxStates, defaultState, id, static_cast<godot::Key>(accel));
            }

            void addRadioCheckItem(const std::string& label, int id = -1, int accel = 0) {
                popup_menu->add_radio_check_item(label.c_str(), id, static_cast<godot::Key>(accel));
            }

            void addRadioCheckShortcut(sunaba::input::Shortcut* shortcut, int id = -1, bool global = false) {
                popup_menu->add_radio_check_shortcut(shortcut->getShortcut(), id, global);
            }

            void addSeparator(const std::string& label = "&quot;&quot;", int id = -1) {
                popup_menu->add_separator(label.c_str(), id);
            }

            void addSubmenuItem(const std::string& label, const std::string& submenu, int id = -1) {
                popup_menu->add_submenu_item(label.c_str(), submenu.c_str(), id);
            }

            void addSubmenuNodeItem(const std::string& label, PopupMenu* submenu, int id = -1) {
                popup_menu->add_submenu_node_item(label.c_str(), submenu->getPopupMenu(), id);
            }

            void clear(bool freeSubmenus = true) {
                popup_menu->clear(freeSubmenus);
            }

            int getFocusedItem() const {
                return popup_menu->get_focused_item();
            }

            int getItemAccelerator(int index) const {
                return popup_menu->get_item_accelerator(index);
            }

            sunaba::core::Texture2D* getItemIcon(int index) const {
                return new sunaba::core::Texture2D(popup_menu->get_item_icon(index));
            }

            Color getItemIconModulate(int index) const {
                return popup_menu->get_item_icon_modulate(index);
            }

            int getItemId(int index) const {
                return popup_menu->get_item_id(index);
            }

            int getItemIndent(int index) const {
                return popup_menu->get_item_indent(index);
            }

            int getItemIndex(int id) const {
                return popup_menu->get_item_index(id);
            }

            std::string getItemLanguage(int index) const {
                return popup_menu->get_item_language(index).utf8().get_data();
            }

            Variant getItemMetadata(int index) const {
                return popup_menu->get_item_metadata(index);
            }

            int getItemMultistate(int index) const {
                return popup_menu->get_item_multistate(index);
            }

            int getItemMultistateMax(int index) const {
                return popup_menu->get_item_multistate_max(index);
            }

            sunaba::input::Shortcut* getItemShortcut(int index) const {
                return new sunaba::input::Shortcut(popup_menu->get_item_shortcut(index));
            }

            std::string getItemSubmenu(int index) const {
                return popup_menu->get_item_submenu(index).utf8().get_data();
            }

            PopupMenu* getItemSubmenuNode(int index) const {
                return new PopupMenu(popup_menu->get_item_submenu_node(index));
            }

            std::string getItemText(int index) const {
                return popup_menu->get_item_text(index).utf8().get_data();
            }

            int getItemTextDirection(int index) const {
                return popup_menu->get_item_text_direction(index);
            }

            std::string getItemTooltip(int index) const {
                return popup_menu->get_item_tooltip(index).utf8().get_data();
            }

            bool isItemCheckable(int index) const {
                return popup_menu->is_item_checkable(index);
            }
    };
}

#endif