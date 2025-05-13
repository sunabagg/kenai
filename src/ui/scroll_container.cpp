#include "scroll_container.h"

namespace sunaba::ui {
    void ScrollContainerProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ScrollContainerProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ScrollContainerProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ScrollContainerProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
}