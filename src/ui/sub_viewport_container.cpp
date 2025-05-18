#include "sub_viewport_container.h"

namespace sunaba::ui {
    void SubViewportContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void SubViewportContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void SubViewportContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void SubViewportContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void SubViewportContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }
}