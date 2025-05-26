#include "v_box_container.h"

namespace sunaba::ui {
    
    void VBoxContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void VBoxContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void VBoxContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void VBoxContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void VBoxContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void VBoxContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void VBoxContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void VBoxContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void VBoxContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void VBoxContainerProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool VBoxContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void VBoxContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant VBoxContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 VBoxContainerProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getMinimumSize();
        }
        return Vector2();
    }

} // namespace sunaba::ui