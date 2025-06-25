#include "popup.h"

namespace lucidfx::desktop {
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

    void PopupSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("popup_hide"), &PopupSignalWrapper::popup_hide);
    }

    void PopupSignalWrapper::popup_hide() {
        if (element != nullptr) {
            Array args;
            element->popupHideEvent->emit(args);
        }
    }

    void bindPopup(sol::state& lua) {
        lua.new_usertype<Popup>("Popup",
            "new", sol::factories(
                []() { return new Popup(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, lucidfx::core::Viewport, lucidfx::desktop::Window>(),
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