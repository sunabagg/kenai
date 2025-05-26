#include "bind_desktop_classes.h"
#include "window.h"

namespace sunaba::desktop {
    void bindDesktopClasses(sol::state& lua) {
        bindWindow(lua);
    }
}