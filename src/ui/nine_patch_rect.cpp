#include "nine_patch_rect.h"

namespace sunaba::ui {
    void NinePatchRectProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void NinePatchRectProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void NinePatchRectProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void NinePatchRectProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void NinePatchRectProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void NinePatchRectProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void NinePatchRectProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void NinePatchRectProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void NinePatchRectProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void NinePatchRectProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool NinePatchRectProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void NinePatchRectProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant NinePatchRectProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 NinePatchRectProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String NinePatchRectProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }
}