#include "bind_desktop_classes.h"
#include "window.h"
#include "popup.h"
#include "popup_panel.h"

namespace sunaba::desktop {
    void bindDesktopClasses(sol::state& lua) {
        bindWindow(lua);
        bindPopup(lua);
        bindPopupPanel(lua);
    }
}