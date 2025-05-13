#include "v_separator.h"

namespace sunaba::ui {
    void VSeparatorProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void VSeparatorProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void VSeparatorProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
}