#include "margin_container.h"

namespace sunaba::ui {
    void MarginContainerProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }

    void MarginContainerProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }

    void MarginContainerProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void MarginContainerProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
}