#include "h_scroll_bar.h"

namespace sunaba::ui {
    void HScrollBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HScrollBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HScrollBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void HScrollBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void HScrollBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void HScrollBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void HScrollBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void HScrollBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }
}