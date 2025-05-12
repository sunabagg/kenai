#include "h_scroll_bar.h"

namespace sunaba::ui {
    void HScrollBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HScrollBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HScrollBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void HScrollBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
}