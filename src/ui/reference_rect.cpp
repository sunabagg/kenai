#include "reference_rect.h"

namespace sunaba::ui {
    void ReferenceRectProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ReferenceRectProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ReferenceRectProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ReferenceRectProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void ReferenceRectProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void ReferenceRectProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void ReferenceRectProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void ReferenceRectProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void ReferenceRectProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }
}