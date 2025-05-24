#include "code_edit.h"

namespace sunaba::ui {
    void CodeEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
}