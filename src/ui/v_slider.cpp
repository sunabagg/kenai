#include "v_slider.h"

namespace sunaba::ui {
    void VSliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void VSliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void VSliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void VSliderProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void VSliderProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void VSliderProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }
}