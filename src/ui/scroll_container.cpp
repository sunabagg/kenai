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
}