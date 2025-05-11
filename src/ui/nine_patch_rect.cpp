#include "nine_patch_rect.h"

namespace sunaba::ui {
    void NinePatchRectProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void NinePatchRectProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void NinePatchRectProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void NinePatchRectProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void NinePatchRectProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void NinePatchRectProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void NinePatchRectProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void NinePatchRectProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void NinePatchRectProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }
}