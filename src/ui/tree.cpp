#include "tree.h"

namespace sunaba::ui {
    void TreeProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TreeProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TreeProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TreeProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TreeProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TreeProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TreeProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TreeProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TreeProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TreeProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool TreeProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }
}