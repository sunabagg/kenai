#include "menu_button.h"

namespace sunaba::ui {
    void MenuButtonProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void MenuButtonProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void MenuButtonProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void MenuButtonProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void MenuButtonProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void MenuButtonProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void MenuButtonProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void MenuButtonProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }
}