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
#include "margin_container.h"
#include "menu_bar.h"
#include "menu_button.h"
#include "nine_patch_rect.h"
#include "option_button.h"
#include "panel.h"
#include "panel_container.h"
#include "range.h"
#include "progress_bar.h"
#include "reference_rect.h"
#include "scroll_bar.h"
#include "h_scroll_bar.h"
#include "v_scroll_bar.h"
#include "scroll_container.h"
#include "separator.h"
#include "h_separator.h"
#include "v_separator.h"
#include "slider.h"
#include "h_slider.h"
#include "v_slider.h"
#include "spin_box.h"
#include "split_container.h"
#include "h_split_container.h"
#include "v_split_container.h"
#include "sub_viewport_container.h"
#include "tab_bar.h"
#include "tab_container.h"
#include "syntax_highlighter.h"
#include "text_edit.h"

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
    bindMarginContainer(lua);
    bindMenuBar(lua);
    bindMenuButton(lua);
    bindNinePatchRect(lua);
    bindOptionButton(lua);
    bindPanel(lua);
    bindPanelContainer(lua);
    bindRange(lua);
    bindProgressBar(lua);
    bindReferenceRect(lua);
    bindScrollBar(lua);
    bindHScrollBar(lua);
    bindVScrollBar(lua);
    bindScrollContainer(lua);
    bindSeparator(lua);
    bindHSeparator(lua);
    bindVSeparator(lua);
    bindSlider(lua);
    bindHSlider(lua);
    bindVSlider(lua);
    bindSpinBox(lua);
    bindSplitContainer(lua);
    bindHSplitContainer(lua);
    bindVSplitContainer(lua);
    bindSubViewportContainer(lua);
    bindTabBar(lua);
    bindTabContainer(lua);
    bindSyntaxHighlighter(lua);
    bindTextEdit(lua);
}