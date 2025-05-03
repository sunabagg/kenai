#include "menu_bar.h"

namespace sunaba::ui {
    void MenuBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void MenuBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void MenuBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void MenuBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
    
    void MenuBarProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void MenuBarProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }
}