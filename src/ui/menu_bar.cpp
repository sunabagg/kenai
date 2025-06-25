#include "menu_bar.h"

namespace lucidware::ui {
    void MenuBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void MenuBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void MenuBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void MenuBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
    
    void MenuBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void MenuBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void MenuBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void MenuBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void MenuBarProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void MenuBarProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool MenuBarProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void MenuBarProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant MenuBarProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 MenuBarProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String MenuBarProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void MenuBarProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool MenuBarProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> MenuBarProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindMenuBar(sol::state& lua) {
        lua.new_usertype<MenuBar>("MenuBar",
            "new", sol::factories(
                []() { return new MenuBar(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::CanvasItem, lucidware::ui::Control>(),
            "flat", sol::property(&MenuBar::isFlat, &MenuBar::setFlat),
            "language", sol::property(&MenuBar::getLanguage, &MenuBar::setLanguage),
            "preferGlobalMenu", sol::property(&MenuBar::isPreferGlobalMenu, &MenuBar::setPreferGlobalMenu),
            "startIndex", sol::property(&MenuBar::getStartIndex, &MenuBar::setStartIndex),
            "switchOnHover", sol::property(&MenuBar::isSwitchOnHover, &MenuBar::setSwitchOnHover),
            "textDirection", sol::property(&MenuBar::getTextDirection, &MenuBar::setTextDirection),
            "getMenuCount", &MenuBar::getMenuCount,
            "getMenuPopup", &MenuBar::getMenuPopup,
            "getMenuTitle", &MenuBar::getMenuTitle,
            "getMenuTooltip", &MenuBar::getMenuTooltip,
            "isMenuDisabled", &MenuBar::isMenuDisabled,
            "isMenuHidden", &MenuBar::isMenuHidden,
            "isNativeMenu", &MenuBar::isNativeMenu,
            "setDisableShortcuts", &MenuBar::setDisableShortcuts,
            "setMenuDisabled", &MenuBar::setMenuDisabled,
            "setMenuHidden", &MenuBar::setMenuHidden,
            "setMenuTitle", &MenuBar::setMenuTitle,
            "setMenuTooltip", &MenuBar::setMenuTooltip,
            "cast", [](Element* e) {
                MenuBarNode* menuBar = Object::cast_to<MenuBarNode>(e->getNode());
                return new MenuBar(menuBar);
            }
        );
    }
}