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

    void PopupMenuSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("id_focused", "id"), &PopupMenuSignalWrapper::id_focused);
        ClassDB::bind_method(D_METHOD("id_pressed", "id"), &PopupMenuSignalWrapper::id_pressed);
        ClassDB::bind_method(D_METHOD("index_pressed", "index"), &PopupMenuSignalWrapper::index_pressed);
        ClassDB::bind_method(D_METHOD("menu_changed"), &PopupMenuSignalWrapper::menu_changed);
    }

    void PopupMenuSignalWrapper::id_focused(int id) {
        if (element != nullptr) {
            Array args;
            args.push_back(id);
            element->idFocusedEvent->emit(args);
        }
    }

    void PopupMenuSignalWrapper::id_pressed(int id) {
        if (element != nullptr) {
            Array args;
            args.push_back(id);
            element->idPressedEvent->emit(args);
        }
    }

    void PopupMenuSignalWrapper::index_pressed(int index) {
        if (element != nullptr) {
            Array args;
            args.push_back(index);
            element->indexPressedEvent->emit(args);
        }
    }

    void PopupMenuSignalWrapper::menu_changed() {
        if (element != nullptr) {
            Array args;
            element->menuChangedEvent->emit(args);
        }
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
            "addIconShortcut", &PopupMenu::addIconShortcut,
            "addItem", &PopupMenu::addItem,
            "addMultistateItem", &PopupMenu::addMultistateItem,
            "addRadioCheckItem", &PopupMenu::addRadioCheckItem,
            "addRadioCheckShortcut", &PopupMenu::addRadioCheckShortcut,
            "addSeparator", &PopupMenu::addSeparator,
            "addShortcut", &PopupMenu::addShortcut,
            "addSubmenuItem", &PopupMenu::addSubmenuItem,
            "addSubmenuNodeItem", &PopupMenu::addSubmenuNodeItem,
            "clear", &PopupMenu::clear,
            "getFocusedItem", &PopupMenu::getFocusedItem,
            "getItemAccelerator", &PopupMenu::getItemAccelerator,
            "getItemIcon", &PopupMenu::getItemIcon,
            "getItemIconMaxWidth", &PopupMenu::getItemIconMaxWidth,
            "getItemIconModulate", &PopupMenu::getItemIconModulate,
            "getItemId", &PopupMenu::getItemId,
            "getItemIndent", &PopupMenu::getItemIndent,
            "getItemIndex", &PopupMenu::getItemIndex,
            "getItemLanguage", &PopupMenu::getItemLanguage,
            "getItemMetadata", &PopupMenu::getItemMetadata,
            "getItemMultistate", &PopupMenu::getItemMultistate,
            "getItemMultistateMax", &PopupMenu::getItemMultistateMax,
            "getItemShortcut", &PopupMenu::getItemShortcut,
            "getItemSubmenu", &PopupMenu::getItemSubmenu,
            "getItemSubmenuNode", &PopupMenu::getItemSubmenuNode,
            "getItemText", &PopupMenu::getItemText,
            "getItemTextDirection", &PopupMenu::getItemTextDirection,
            "getItemTooltip", &PopupMenu::getItemTooltip,
            "isItemCheckable", &PopupMenu::isItemCheckable,
            "isItemChecked", &PopupMenu::isItemChecked,
            "isItemDisabled", &PopupMenu::isItemDisabled,
            "isItemRadioCheckable", &PopupMenu::isItemRadioCheckable,
            "isItemSeparator", &PopupMenu::isItemSeparator,
            "isItemShortcutDisabled", &PopupMenu::isItemShortcutDisabled,
            "isNativeMenu", &PopupMenu::isNativeMenu,
            "isSystemMenu", &PopupMenu::isSystemMenu,
            "removeItem", &PopupMenu::removeItem,
            "scrollToItem", &PopupMenu::scrollToItem,
            "setFocusedItem", &PopupMenu::setFocusedItem,
            "setItemAccelerator", &PopupMenu::setItemAccelerator,
            "setItemAsCheckable", &PopupMenu::setItemAsCheckable,
            "setItemAsRadioCheckable", &PopupMenu::setItemAsRadioCheckable,
            "setItemAsSeparator", &PopupMenu::setItemAsSeparator,
            "setItemChecked", &PopupMenu::setItemChecked,
            "setItemDisabled", &PopupMenu::setItemDisabled,
            "setItemIcon", &PopupMenu::setItemIcon,
            "setItemIconMaxWidth", &PopupMenu::setItemIconMaxWidth,
            "setItemIconModulate", &PopupMenu::setItemIconModulate,
            "setItemId", &PopupMenu::setItemId,
            "setItemIndent", &PopupMenu::setItemIndent,
            "setItemLanguage", &PopupMenu::setItemLanguage,
            "setItemMetadata", &PopupMenu::setItemMetadata,
            "setItemMultistate", &PopupMenu::setItemMultistate,
            "setItemMultistateMax", &PopupMenu::setItemMultistateMax,
            "setItemShortcut", &PopupMenu::setItemShortcut,
            "setItemShortcutDisabled", &PopupMenu::setItemShortcutDisabled,
            "setItemSubmenu", &PopupMenu::setItemSubmenu,
            "setItemSubmenuNode", &PopupMenu::setItemSubmenuNode,
            "setItemText", &PopupMenu::setItemText,
            "setItemTextDirection", &PopupMenu::setItemTextDirection,
            "setItemTooltip", &PopupMenu::setItemTooltip,
            "toggleItemChecked", &PopupMenu::toggleItemChecked,
            "toggleItemMultistate", &PopupMenu::toggleItemMultistate,
            "cast", [](Element* e) {
                PopupMenuNode* popup_menu = Object::cast_to<PopupMenuNode>(e->getNode());
                return new PopupMenu(popup_menu);
            }
        );
    }
}