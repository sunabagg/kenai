#include "progress_bar.h"

namespace sunaba::ui {
    void ProgressBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ProgressBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ProgressBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ProgressBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ProgressBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ProgressBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }
}