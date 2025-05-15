#include "split_container.h"

namespace sunaba::ui {
    void SplitContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }
}