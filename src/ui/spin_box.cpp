#include "spin_box.h"

namespace sunaba::ui {
    void SpinBoxProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SpinBoxProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SpinBoxProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void SpinBoxProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
}