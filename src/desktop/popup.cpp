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
}