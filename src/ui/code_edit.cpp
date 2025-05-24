#include "code_edit.h"

namespace sunaba::ui {
    void CodeEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void CodeEditProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void CodeEditProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void CodeEditProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }
}