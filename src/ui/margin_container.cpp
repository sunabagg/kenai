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
}