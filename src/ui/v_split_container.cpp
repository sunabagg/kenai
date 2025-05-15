#include "v_split_container.h"

namespace sunaba::ui {
    void VSplitContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void VSplitContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void VSplitContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
}