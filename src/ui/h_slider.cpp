#include "h_slider.h"

namespace sunaba::ui {
    void HSliderProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HSliderProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HSliderProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }
}