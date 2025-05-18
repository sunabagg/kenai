#include "tab_bar.h"

namespace sunaba::ui {
    void TabBarProxy::_enter_tree() {
        if (element) {
            element->enterTree();
        }
    }

    void TabBarProxy::_exit_tree() {
        if (element) {
            element->exitTree();
        }
    }

    void TabBarProxy::_ready() {
        if (element) {
            element->ready();
        }
    }
} // namespace sunaba::ui