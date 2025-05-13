#include "slider.h"

namespace sunaba::ui {
    void SliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void SliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void SliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
}