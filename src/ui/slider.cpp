#include "slider.h"

namespace sunaba::ui {
    void SliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void SliderProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void SliderProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void SliderProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void SliderProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void SliderProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void SliderProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void SliderProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool SliderProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void SliderProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant SliderProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 SliderProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String SliderProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void SliderProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }
}