#include "h_separator.h"

namespace sunaba::ui {
    void HSeparatorProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HSeparatorProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HSeparatorProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
}