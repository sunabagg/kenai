#include "h_separator.h"

namespace sunaba::ui {
    void HSeparatorProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HSeparatorProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HSeparatorProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void HSeparatorProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void HSeparatorProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void HSeparatorProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }
}