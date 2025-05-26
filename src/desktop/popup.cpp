#include "popup.h"

namespace sunaba::desktop {
    void PopupProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void PopupProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void PopupProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void PopupProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void PopupProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void PopupProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void PopupProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void PopupProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void PopupProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    Vector2 PopupProxy::_get_contents_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getContentsMinimumSize();
        }
        return PopupNode::_get_contents_minimum_size();
    }

    void bindPopup(sol::state& lua) {
        lua.new_usertype<Popup>("Popup",
            sol::constructors<Popup()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::Viewport, sunaba::desktop::Window>(),
            "borderless", sol::property(
                &Popup::getBorderless,
                &Popup::setBorderless
            ),
            "popupWindow", sol::property(
                &Popup::getPopupWindow,
                &Popup::setPopupWindow
            ),
            "transient", sol::property(
                &Popup::getTransient,
                &Popup::setTransient
            ),
            "unresizable", sol::property(
                &Popup::getUnresizable,
                &Popup::setUnresizable
            ),
            "visible", sol::property(
                &Popup::getVisible,
                &Popup::setVisible
            ),
            "wrapControls", sol::property(
                &Popup::getWrapControls,
                &Popup::setWrapControls
            ),
            "cast", [](Element* e) {
                PopupNode* popup = Object::cast_to<PopupNode>(e->getNode());
                return new Popup(popup);
            }
        );
    }
}