#include "scroll_bar.h"

namespace sunaba::ui {
    void ScrollBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ScrollBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ScrollBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ScrollBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ScrollBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ScrollBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void ScrollBarProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void ScrollBarProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void ScrollBarProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void ScrollBarProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }
}