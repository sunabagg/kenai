#include "margin_container.h"

namespace sunaba::ui {
    void MarginContainerProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void MarginContainerProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void MarginContainerProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void MarginContainerProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void MarginContainerProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void MarginContainerProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void MarginContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void MarginContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void MarginContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void MarginContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool MarginContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void MarginContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }
}