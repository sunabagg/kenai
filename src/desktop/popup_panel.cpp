#include "popup_panel.h"

namespace lucidware::desktop {
    void PopupPanelProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void PopupPanelProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void PopupPanelProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void PopupPanelProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void PopupPanelProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void PopupPanelProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void PopupPanelProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void PopupPanelProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void PopupPanelProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    Vector2 PopupPanelProxy::_get_contents_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getContentsMinimumSize();
        }
        return PopupPanelNode::get_contents_minimum_size();
    }

    void bindPopupPanel(sol::state& lua) {
        lua.new_usertype<PopupPanel>("PopupPanel",
            "new", sol::factories(
                []() { return new PopupPanel(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidware::core::Viewport, Window, Popup>(),
            "transparent", sol::property(&PopupPanel::getTransparent, &PopupPanel::setTransparent),
            "transparentBg", sol::property(&PopupPanel::getTransparentBg, &PopupPanel::setTransparentBg),
            "cast", [](Element* e) {
                PopupPanelNode* node = Object::cast_to<PopupPanelNode>(e->getNode());
                return new PopupPanel(node);
            }
        );
    }
}