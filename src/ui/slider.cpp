#include "slider.h"

namespace sunaba::ui {
    void SliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void SliderProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void SliderProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }
}