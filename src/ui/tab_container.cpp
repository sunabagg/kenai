#include "tab_container.h"

namespace sunaba::ui {
    void TabContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TabContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TabContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
}