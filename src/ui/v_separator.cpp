#include "v_separator.h"

namespace sunaba::ui {
    void VSeparatorProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void VSeparatorProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void VSeparatorProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void VSeparatorProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void VSeparatorProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }
}