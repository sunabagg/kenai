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
#include "button.h"
#include "check_box.h"
#include "check_button.h"
#include "container.h"
#include "aspect_ratio_container.h"
#include "box_container.h"
#include "center_container.h"
#include "flow_container.h"
#include "grid_container.h"
#include "h_box_container.h"
#include "h_flow_container.h"
#include "item_list.h"
#include "label.h"
#include "line_edit.h"
#include "link_button.h"

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
    bindButton(lua);
    bindCheckBox(lua);
    bindCheckButton(lua);
    bindContainer(lua);
    bindAspectRatioContainer(lua);
    bindBoxContainer(lua);
    bindCenterContainer(lua);
    bindFlowContainer(lua);
    bindGridContainer(lua);
    bindHBoxContainer(lua);
    bindHFlowContainer(lua);
    bindItemList(lua);
    bindLabel(lua);
    bindLineEdit(lua);
    bindLinkButton(lua);
}