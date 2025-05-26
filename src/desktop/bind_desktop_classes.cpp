#include "bind_desktop_classes.h"
#include "window.h"
#include "popup.h"

namespace sunaba::desktop {
    void bindDesktopClasses(sol::state& lua) {
        bindWindow(lua);
        bindPopup(lua);
    }
}