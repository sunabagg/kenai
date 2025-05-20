#include "text_edit.h"

namespace sunaba::ui {
    void TextEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
}