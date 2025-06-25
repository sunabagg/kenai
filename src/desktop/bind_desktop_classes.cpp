#include "bind_desktop_classes.h"
#include "window.h"
#include "popup.h"
#include "popup_panel.h"
#include "popup_menu.h"

namespace lucidware::desktop {
    void bindDesktopClasses(sol::state& lua) {
        bindWindow(lua);
        bindPopup(lua);
        bindPopupPanel(lua);
        bindPopupMenu(lua);
    }
}