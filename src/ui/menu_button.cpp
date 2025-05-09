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
}