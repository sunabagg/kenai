#include "tree.h"

namespace sunaba::ui {
    void TreeProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TreeProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }
}