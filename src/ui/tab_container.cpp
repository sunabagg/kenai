#include "tab_container.h"

namespace sunaba::ui {
    void TabContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
}