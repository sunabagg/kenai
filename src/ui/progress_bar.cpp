#include "progress_bar.h"

namespace sunaba::ui {
    void ProgressBarProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void ProgressBarProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void ProgressBarProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
    
    void ProgressBarProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }
}