#include "tree.h"

namespace kenai::ui {
    void TreeProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TreeProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TreeProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TreeProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TreeProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TreeProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TreeProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TreeProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TreeProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TreeProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool TreeProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void TreeProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant TreeProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 TreeProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getMinimumSize();
        }
        return Vector2();
    }

    String TreeProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void TreeProxy::_gui_input(const Ref<InputEvent> &event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool TreeProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    // Object* TreeProxy::_make_custom_tooltip(const String &for_text) const {
    //     if (this->element != nullptr) {
    //         return this->element->makeCustomTooltip(for_text);
    //     }
    //     return nullptr;  
    // }

    TypedArray<Vector3i> TreeProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void TreeSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("button_clicked", "item", "column", "id", "mouse_button_index"), &TreeSignalWrapper::button_clicked);
        ClassDB::bind_method(D_METHOD("cell_selected"), &TreeSignalWrapper::cell_selected);
        ClassDB::bind_method(D_METHOD("check_propagated_to_item", "item", "column"), &TreeSignalWrapper::check_propagated_to_item);
        ClassDB::bind_method(D_METHOD("column_title_clicked", "column", "mouse_button_index"), &TreeSignalWrapper::column_title_clicked);
        ClassDB::bind_method(D_METHOD("custom_item_clicked", "column"), &TreeSignalWrapper::custom_item_clicked);
        ClassDB::bind_method(D_METHOD("custom_popup_edited", "arrow_clicked"), &TreeSignalWrapper::custom_popup_edited);
        ClassDB::bind_method(D_METHOD("empty_clicked", "click_position", "mouse_button_index"), &TreeSignalWrapper::empty_clicked);
        ClassDB::bind_method(D_METHOD("item_activated"), &TreeSignalWrapper::item_activated);
        ClassDB::bind_method(D_METHOD("item_collapsed", "item"), &TreeSignalWrapper::item_collapsed);
        ClassDB::bind_method(D_METHOD("item_edited"), &TreeSignalWrapper::item_edited);
        ClassDB::bind_method(D_METHOD("item_icon_double_clicked"), &TreeSignalWrapper::item_icon_double_clicked);
        ClassDB::bind_method(D_METHOD("item_mouse_selected", "mouse_position", "mouse_button_index"), &TreeSignalWrapper::item_mouse_selected);
        ClassDB::bind_method(D_METHOD("item_selected"), &TreeSignalWrapper::item_selected);
        ClassDB::bind_method(D_METHOD("multi_selected", "item", "column", "selected"), &TreeSignalWrapper::multi_selected);
        ClassDB::bind_method(D_METHOD("nothing_selected"), &TreeSignalWrapper::nothing_selected);
    }

    void TreeSignalWrapper::button_clicked(godot::TreeItem* item, int column, int id, int mouse_button_index) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(item);
            args.push_back(column);
            args.push_back(id);
            args.push_back(mouse_button_index);
            this->element->getButtonClickedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::cell_selected() {
        if (this->element != nullptr) {
            Array args;
            this->element->getCellSelectedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::check_propagated_to_item(godot::TreeItem* item, int column) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(item);
            args.push_back(column);
            this->element->getCheckPropagatedToItemEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::column_title_clicked(int column, int mouse_button_index) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(column);
            args.push_back(mouse_button_index);
            this->element->getColumnTitleClickedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::custom_item_clicked(int column) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(column);
            this->element->getCustomItemClickedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::custom_popup_edited(bool arrow_clicked) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(arrow_clicked);
            this->element->getCustomPopupEditedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::empty_clicked(const Vector2& click_position, int mouse_button_index) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(click_position);
            args.push_back(mouse_button_index);
            this->element->getEmptyClickedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::item_activated() {
        if (this->element != nullptr) {
            Array args;
            this->element->getItemActivatedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::item_collapsed(godot::TreeItem* item) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(item);
            this->element->getItemCollapsedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::item_edited() {
        if (this->element != nullptr) {
            Array args;
            this->element->getItemEditedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::item_icon_double_clicked() {
        if (this->element != nullptr) {
            Array args;
            this->element->getItemIconDoubleClickedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::item_mouse_selected(const Vector2& mouse_position, int mouse_button_index) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(mouse_position);
            args.push_back(mouse_button_index);
            this->element->getItemMouseSelectedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::item_selected() {
        if (this->element != nullptr) {
            Array args;
            this->element->getItemSelectedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::multi_selected(godot::TreeItem* item, int column, bool selected) {
        if (this->element != nullptr) {
            Array args;
            args.push_back(item);
            args.push_back(column);
            args.push_back(selected);
            this->element->getMultiSelectedEvent()->emit(args);
        }
    }

    void TreeSignalWrapper::nothing_selected() {
        if (this->element != nullptr) {
            Array args;
            this->element->getNothingSelectedEvent()->emit(args);
        }
    }

    void bindTree(sol::state &lua) {
        lua.new_usertype<Tree>("Tree",
            "new", sol::factories(
                []() { return new Tree(); }
            ),
            sol::base_classes, sol::bases<BaseObject, Element, kenai::core::CanvasItem, Control>(),
            "allowReselect", sol::property(
                &Tree::getAllowReselect,
                &Tree::setAllowReselect
            ),
            "allowRmbSelect", sol::property(
                &Tree::getAllowRmbSelect,
                &Tree::setAllowRmbSelect
            ),
            "allowSearch", sol::property(
                &Tree::getAllowSearch,
                &Tree::setAllowSearch
            ),
            "autoTooltip", sol::property(
                &Tree::getAutoTooltip,
                &Tree::setAutoTooltip
            ),
            "clipContents", sol::property(
                &Tree::getClipContents,
                &Tree::setClipContents
            ),
            "columnTitlesVisible", sol::property(
                &Tree::getColumnTitlesVisible,
                &Tree::setColumnTitlesVisible
            ),
            "columns", sol::property(
                &Tree::getColumns,
                &Tree::setColumns
            ),
            "dropModeFlags", sol::property(
                &Tree::getDropModeFlags,
                &Tree::setDropModeFlags
            ),
            "enableRecursiveFolding", sol::property(
                &Tree::getEnableRecursiveFolding,
                &Tree::setEnableRecursiveFolding
            ),
            "focusMode", sol::property(
                &Tree::getFocusMode,
                &Tree::setFocusMode
            ),
            "hideFolding", sol::property(
                &Tree::getHideFolding,
                &Tree::setHideFolding
            ),
            "hideRoot", sol::property(
                &Tree::getHideRoot,
                &Tree::setHideRoot
            ),
            "scrollHorizontalEnabled", sol::property(
                &Tree::getScrollHorizontalEnabled,
                &Tree::setScrollHorizontalEnabled
            ),
            "scrollVerticalEnabled", sol::property(
                &Tree::getScrollVerticalEnabled,
                &Tree::setScrollVerticalEnabled
            ),
            "selectMode", sol::property(
                &Tree::getSelectMode,
                &Tree::setSelectMode
            ),
            "buttonClicked", sol::property(
                &Tree::getButtonClickedEvent,
                &Tree::setButtonClickedEvent
            ),
            "cellSelected", sol::property(
                &Tree::getCellSelectedEvent,
                &Tree::setCellSelectedEvent
            ),
            "checkPropagatedToItem", sol::property(
                &Tree::getCheckPropagatedToItemEvent,
                &Tree::setCheckPropagatedToItemEvent
            ),
            "columnTitleClicked", sol::property(
                &Tree::getColumnTitleClickedEvent,
                &Tree::setColumnTitleClickedEvent
            ),
            "customItemClicked", sol::property(
                &Tree::getCustomItemClickedEvent,
                &Tree::setCustomItemClickedEvent
            ),
            "customPopupEdited", sol::property(
                &Tree::getCustomPopupEditedEvent,
                &Tree::setCustomPopupEditedEvent
            ),
            "emptyClicked", sol::property(
                &Tree::getEmptyClickedEvent,
                &Tree::setEmptyClickedEvent
            ),
            "itemActivated", sol::property(
                &Tree::getItemActivatedEvent,
                &Tree::setItemActivatedEvent
            ),
            "itemCollapsed", sol::property(
                &Tree::getItemCollapsedEvent,
                &Tree::setItemCollapsedEvent
            ),
            "itemEdited", sol::property(
                &Tree::getItemEditedEvent,
                &Tree::setItemEditedEvent
            ),
            "itemIconDoubleClicked", sol::property(
                &Tree::getItemIconDoubleClickedEvent,
                &Tree::setItemIconDoubleClickedEvent
            ),
            "itemMouseSelected", sol::property(
                &Tree::getItemMouseSelectedEvent,
                &Tree::setItemMouseSelectedEvent
            ),
            "itemSelected", sol::property(
                &Tree::getItemSelectedEvent,
                &Tree::setItemSelectedEvent
            ),
            "multiSelected", sol::property(
                &Tree::getMultiSelectedEvent,
                &Tree::setMultiSelectedEvent
            ),
            "nothingSelected", sol::property(
                &Tree::getNothingSelectedEvent,
                &Tree::setNothingSelectedEvent
            ),
            "clear", &Tree::clear,
            "createItem", &Tree::createItem,
            "deselectAll", &Tree::deselectAll,
            "editSelected", &Tree::editSelected,
            "ensureCursorIsVisible", &Tree::ensureCursorIsVisible,
            "getButtonIdAtPosition", &Tree::getButtonIdAtPosition,
            "getColumnAtPosition", &Tree::getColumnAtPosition,
            "getColumnExpandRatio", &Tree::getColumnExpandRatio,
            "getColumnTitle", &Tree::getColumnTitle,
            "getColumnTitleAlignment", &Tree::getColumnTitleAlignment,
            "getColumnTitleDirection", &Tree::getColumnTitleDirection,
            "getColumnTitleLanguage", &Tree::getColumnTitleLanguage,
            "getColumnWidth", &Tree::getColumnWidth,
            "getCustomPopupRect", &Tree::getCustomPopupRect,
            "getDropSelectionAtPosition", &Tree::getDropSelectionAtPosition,
            "getEdited", &Tree::getEdited,
            "getEditedColumn", &Tree::getEditedColumn,
            "getItemAreaRect", &Tree::getItemAreaRect,
            "getItemAtPosition", &Tree::getItemAtPosition,
            "getNextSelected", &Tree::getNextSelected,
            "getPressedButton", &Tree::getPressedButton,
            "getRoot", &Tree::getRoot,
            "getScroll", &Tree::getScroll,
            "getSelected", &Tree::getSelected,
            "getSelectedColumn", &Tree::getSelectedColumn,
            "isColumnClippingContent", &Tree::isColumnClippingContent,
            "isColumnExpanding", &Tree::isColumnExpanding,
            "scrollToItem", &Tree::scrollToItem,
            "setColumnCustomMinimumWidth", &Tree::setColumnCustomMinimumWidth,
            "setColumnExpand", &Tree::setColumnExpand,
            "setColumnExpandRatio", &Tree::setColumnExpandRatio,
            "setColumnTitle", &Tree::setColumnTitle,
            "setColumnTitleAlignment", &Tree::setColumnTitleAlignment,
            "setColumnTitleDirection", &Tree::setColumnTitleDirection,
            "setColumnTitleLanguage", &Tree::setColumnTitleLanguage,
            "setSelected", &Tree::setSelected,
            "cast", [](Element* element) {
                auto* ce = dynamic_cast<Tree*>(element);
                if (ce != nullptr) {
                    return ce;
                }
                godot::Tree* treeNode = Object::cast_to<godot::Tree>(element->getNode());
                return new Tree(treeNode);
            }
        );
    }
}