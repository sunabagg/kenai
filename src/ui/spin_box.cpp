#include "spin_box.h"

namespace sunaba::ui {
    void SpinBoxProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SpinBoxProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SpinBoxProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void SpinBoxProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void SpinBoxProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void SpinBoxProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void SpinBoxProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void SpinBoxProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void SpinBoxProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void SpinBoxProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool SpinBoxProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void SpinBoxProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant SpinBoxProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 SpinBoxProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }
}