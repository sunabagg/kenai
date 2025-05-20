#include "text_edit.h"

namespace sunaba::ui {
    void TextEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TextEditProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TextEditProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }
}