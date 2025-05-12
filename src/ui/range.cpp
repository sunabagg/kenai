#include "range.h"

namespace sunaba::ui {
    void RangeProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void RangeProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void RangeProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void RangeProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void RangeProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void RangeProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void RangeProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }
}