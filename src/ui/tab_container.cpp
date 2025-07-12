#include "tab_container.h"

namespace kenai::ui {
    void TabContainerProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TabContainerProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TabContainerProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TabContainerProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TabContainerProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TabContainerProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TabContainerProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TabContainerProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TabContainerProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TabContainerProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool TabContainerProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void TabContainerProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant TabContainerProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 TabContainerProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->_getMinimumSize();
        }
        return Vector2();
    }

    String TabContainerProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void TabContainerProxy::_gui_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }

    bool TabContainerProxy::_has_point(const Vector2 &point) const {
        if (element != nullptr) {
            return element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> TabContainerProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (element != nullptr) {
            return element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    PackedInt32Array TabContainerProxy::_get_allowed_size_flags_horizontal() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsHorizontal();
        }
        return PackedInt32Array();
    }

    PackedInt32Array TabContainerProxy::_get_allowed_size_flags_vertical() const {
        if (element != nullptr) {
            return element->getAllowedSizeFlagsVertical();
        }
        return PackedInt32Array();
    }

    void TabContainerSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("active_tab_rearranged", "tab"), &TabContainerSignalWrapper::active_tab_rearranged);
        ClassDB::bind_method(D_METHOD("pre_popup_pressed"), &TabContainerSignalWrapper::pre_popup_pressed);
        ClassDB::bind_method(D_METHOD("tab_button_pressed", "tab"), &TabContainerSignalWrapper::tab_button_pressed);
        ClassDB::bind_method(D_METHOD("tab_changed", "tab"), &TabContainerSignalWrapper::tab_changed);
        ClassDB::bind_method(D_METHOD("tab_clicked", "tab"), &TabContainerSignalWrapper::tab_clicked);
        ClassDB::bind_method(D_METHOD("tab_hovered", "tab"), &TabContainerSignalWrapper::tab_hovered);
        ClassDB::bind_method(D_METHOD("tab_selected", "tab"), &TabContainerSignalWrapper::tab_selected);
    }

    void TabContainerSignalWrapper::active_tab_rearranged(int tab) {
        if (element != nullptr && element->getActiveTabRearrangedEvent() != nullptr) {
            Array args;
            args.push_back(tab);
            element->getActiveTabRearrangedEvent()->emit(args);
        }
    }

    void TabContainerSignalWrapper::pre_popup_pressed() {
        if (element != nullptr && element->getPrePopupPressedEvent() != nullptr) {
            Array args;
            element->getPrePopupPressedEvent()->emit(args);
        }
    }

    void TabContainerSignalWrapper::tab_button_pressed(int tab) {
        if (element != nullptr && element->getTabButtonPressedEvent() != nullptr) {
            Array args;
            args.push_back(tab);
            element->getTabButtonPressedEvent()->emit(args);
        }
    }

    void TabContainerSignalWrapper::tab_changed(int tab) {
        if (element != nullptr && element->getTabChangedEvent() != nullptr) {
            Array args;
            args.push_back(tab);
            element->getTabChangedEvent()->emit(args);
        }
    }

    void TabContainerSignalWrapper::tab_clicked(int tab) {
        if (element != nullptr && element->getTabClickedEvent() != nullptr) {
            Array args;
            args.push_back(tab);
            element->getTabClickedEvent()->emit(args);
        }
    }

    void TabContainerSignalWrapper::tab_hovered(int tab) {
        if (element != nullptr && element->getTabHoveredEvent() != nullptr) {
            Array args;
            args.push_back(tab);
            element->getTabHoveredEvent()->emit(args);
        }
    }

    void TabContainerSignalWrapper::tab_selected(int tab) {
        if (element != nullptr && element->getTabSelectedEvent() != nullptr) {
            Array args;
            args.push_back(tab);
            element->getTabSelectedEvent()->emit(args);
        }
    }

    void bindTabContainer(sol::state& lua) {
        lua.new_usertype<TabContainer>("TabContainer",
            "new", sol::factories(
                []() { return new TabContainer(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, kenai::core::CanvasItem, Control, Container>(),
            "allTabsInFront", sol::property(&TabContainer::getAllTabsInFront, &TabContainer::setAllTabsInFront),
            "clipTabs", sol::property(&TabContainer::getClipTabs, &TabContainer::setClipTabs),
            "currentTab", sol::property(&TabContainer::getCurrentTab, &TabContainer::setCurrentTab),
            "deselectEnabled", sol::property(&TabContainer::getDeselectEnabled, &TabContainer::setDeselectEnabled),
            "dragToRearrangeEnabled", sol::property(&TabContainer::getDragToRearrangeEnabled, &TabContainer::setDragToRearrangeEnabled),
            "tabAlignment", sol::property(&TabContainer::getTabAlignment, &TabContainer::setTabAlignment),
            "tabFocusMode", sol::property(&TabContainer::getTabFocusMode, &TabContainer::setTabFocusMode),
            "tabsPosition", sol::property(&TabContainer::getTabsPosition, &TabContainer::setTabsPosition),
            "tabsRearrangeGroup", sol::property(&TabContainer::getTabsRearrangeGroup, &TabContainer::setTabsRearrangeGroup),
            "tabsVisible", sol::property(&TabContainer::getTabsVisible, &TabContainer::setTabsVisible),
            "useHiddenTabsForMinSize", sol::property(&TabContainer::getUseHiddenTabsForMinSize, &TabContainer::setUseHiddenTabsForMinSize),
            "activeTabRearranged", sol::property(&TabContainer::getActiveTabRearrangedEvent, &TabContainer::setActiveTabRearrangedEvent),
            "prePopupPressed", sol::property(&TabContainer::getPrePopupPressedEvent, &TabContainer::setPrePopupPressedEvent),
            "tabButtonPressed", sol::property(&TabContainer::getTabButtonPressedEvent, &TabContainer::setTabButtonPressedEvent),
            "tabChanged", sol::property(&TabContainer::getTabChangedEvent, &TabContainer::setTabChangedEvent),
            "tabClicked", sol::property(&TabContainer::getTabClickedEvent, &TabContainer::setTabClickedEvent),
            "tabHovered", sol::property(&TabContainer::getTabHoveredEvent, &TabContainer::setTabHoveredEvent),
            "tabSelected", sol::property(&TabContainer::getTabSelectedEvent, &TabContainer::setTabSelectedEvent),
            "getCurrentTabControl", &TabContainer::getCurrentTabControl,
            "getPopup", &TabContainer::getPopup,
            "getPreviousTab", &TabContainer::getPreviousTab,
            "getTabBar", &TabContainer::getTabBar,
            "getTabButtonIcon", &TabContainer::getTabButtonIcon,
            "getTabControl", &TabContainer::getTabControl,
            "getTabCount", &TabContainer::getTabCount,
            "getTabIcon", &TabContainer::getTabIcon,
            "getTabIconMaxWidth", &TabContainer::getTabIconMaxWidth,
            "getTabIdxAtPoint", &TabContainer::getTabIdxAtPoint,
            "getTabIdxFromControl", &TabContainer::getTabIdxFromControl,
            "getTabMetadata", &TabContainer::getTabMetadata,
            "getTabTitle", &TabContainer::getTabTitle,
            "getTabTooltip", &TabContainer::getTabTooltip,
            "isTabDisabled", &TabContainer::isTabDisabled,
            "isTabHidden", &TabContainer::isTabHidden,
            "selectNextAvailable", &TabContainer::selectNextAvailable,
            "selectPreviousAvailable", &TabContainer::selectPreviousAvailable,
            "setPopup", &TabContainer::setPopup,
            "setTabButtonIcon", &TabContainer::setTabButtonIcon,
            "setTabDisabled", &TabContainer::setTabDisabled,
            "setTabHidden", &TabContainer::setTabHidden,
            "setTabIcon", &TabContainer::setTabIcon,
            "setTabIconMaxWidth", &TabContainer::setTabIconMaxWidth,
            "setTabMetadata", &TabContainer::setTabMetadata,
            "setTabTitle", &TabContainer::setTabTitle,
            "setTabTooltip", &TabContainer::setTabTooltip,
            "cast", [](Element* e) {
                auto* ce = dynamic_cast<TabContainer*>(e);
                if (ce != nullptr) {
                    return ce;
                }
                TabContainerNode* tab = Object::cast_to<TabContainerNode>(e->getNode());
                return new TabContainer(tab);
            }
        );

    }
}