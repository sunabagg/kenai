#include "spin_box.h"

namespace sunaba::ui {
    void SpinBoxProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SpinBoxProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SpinBoxProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void SpinBoxProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void SpinBoxProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void SpinBoxProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }
}