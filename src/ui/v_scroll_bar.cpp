#include "v_scroll_bar.h"

namespace sunaba::ui {
    void VScrollBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void VScrollBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void VScrollBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void VScrollBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void VScrollBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void VScrollBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void VScrollBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void VScrollBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }
}