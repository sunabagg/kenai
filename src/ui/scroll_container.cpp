#include "scroll_container.h"

namespace sunaba::ui {
    void ScrollContainerProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ScrollContainerProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ScrollContainerProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ScrollContainerProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ScrollContainerProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ScrollContainerProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void ScrollContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void ScrollContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void ScrollContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void ScrollContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool ScrollContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void ScrollContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant ScrollContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ScrollContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String ScrollContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position);
        }
        return String();
    }
}