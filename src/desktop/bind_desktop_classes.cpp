#include "bind_desktop_classes.h"
#include "window.h"
#include "popup.h"
#include "popup_panel.h"
#include "popup_menu.h"
#include "accept_dialog.h"

namespace sunaba::desktop {
    void bindDesktopClasses(sol::state& lua) {
        bindWindow(lua);
        bindPopup(lua);
        bindPopupPanel(lua);
        bindPopupMenu(lua);
        bindAcceptDialog(lua);
    }
}