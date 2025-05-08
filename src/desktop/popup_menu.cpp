#include "popup_menu.h"

namespace sunaba::desktop {
    void PopupMenuProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void PopupMenuProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void PopupMenuProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void PopupMenuProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void PopupMenuProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void PopupMenuProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void PopupMenuProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void PopupMenuProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void PopupMenuProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    Vector2 PopupMenuProxy::_get_contents_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getContentsMinimumSize();
        }
        return PopupMenuNode::get_contents_minimum_size();
    }

    void bindPopupMenu(sol::state& lua) {
        lua.new_usertype<PopupMenu>("PopupMenu",
            sol::constructors<PopupMenu()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::Viewport, Window, Popup>(),
            "allowSearch", sol::property(&PopupMenu::getAllowSearch, &PopupMenu::setAllowSearch),
            "hideOnCheckableItemSelection", sol::property(&PopupMenu::getHideOnCheckableItemSelection, &PopupMenu::setHideOnCheckableItemSelection),
            "hideOnItemSelection", sol::property(&PopupMenu::getHideOnItemSelection, &PopupMenu::setHideOnItemSelection),
            "hideOnStateItemSelection", sol::property(&PopupMenu::getHideOnStateItemSelection, &PopupMenu::setHideOnStateItemSelection),
            "itemCount", sol::property(&PopupMenu::getItemCount, &PopupMenu::setItemCount),
            "preferNativeMenu", sol::property(&PopupMenu::getPreferNativeMenu, &PopupMenu::setPreferNativeMenu),
            "submenuPopupDelay", sol::property(&PopupMenu::getSubmenuPopupDelay, &PopupMenu::setSubmenuPopupDelay),
            "systemMenuId", sol::property(&PopupMenu::getSystemMenuId, &PopupMenu::setSystemMenuId),
            "transparent", sol::property(&PopupMenu::getTransparent, &PopupMenu::setTransparent),
            "transparentBg", sol::property(&PopupMenu::getTransparentBg, &PopupMenu::setTransparentBg),
            "idFocused", sol::property(&PopupMenu::getIdFocusedEvent, &PopupMenu::setIdFocusedEvent),
            "idPressed", sol::property(&PopupMenu::getIdPressedEvent, &PopupMenu::setIdPressedEvent),
            "indexPressed", sol::property(&PopupMenu::getIndexPressedEvent, &PopupMenu::setIndexPressedEvent),
            "menuChanged", sol::property(&PopupMenu::getMenuChangedEvent, &PopupMenu::setMenuChangedEvent),
            "activateItemByEvent", &PopupMenu::activateItemByEvent,
            "addCheckItem", &PopupMenu::addCheckItem,
            "addCheckShortcut", &PopupMenu::addCheckShortcut,
            "addIconCheckItem", &PopupMenu::addIconCheckItem,
            "addIconCheckShortcut", &PopupMenu::addIconCheckShortcut,
            "addIconItem", &PopupMenu::addIconItem,
            "addIconRadioCheckItem", &PopupMenu::addIconRadioCheckItem,
            "addIconRadioCheckShortcut", &PopupMenu::addIconRadioCheckShortcut,
    }
}