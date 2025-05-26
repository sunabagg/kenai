#include "bind_ui_classes.h"

#include "style_box.h"
#include "style_box_empty.h"
#include "style_box_flat.h"
#include "style_box_line.h"
#include "style_box_texture.h"
#include "theme.h"
#include "control.h"
#include "base_button.h"
#include "button_group.h"

void sunaba::ui::bindUIClasses(sol::state& lua) {
    bindStyleBox(lua);
    bindStyleBoxEmpty(lua);
    bindStyleBoxFlat(lua);
    bindStyleBoxLine(lua);
    bindStyleBoxTexture(lua);
    bindTheme(lua);
    bindControl(lua);
    bindBaseButton(lua);
    bindButtonGroup(lua);
}