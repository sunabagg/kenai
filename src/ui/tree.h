#ifndef TREE_H
#define TREE_H

#include <godot_cpp/classes/tree.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTree godot::Tree

#include "control.h"
#include "tree_item.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace kenai::core;

namespace kenai::ui {
    void bindTree(sol::state& lua);

    class Tree;

    class TreeProxy : public GodotTree {
        GDCLASS(TreeProxy, GodotTree)
        protected:
            static void _bind_methods() {}
        public:
            kenai::ui::Tree* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            void _draw() override;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class TreeSignalWrapper : public Object {
        GDCLASS(TreeSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            kenai::ui::Tree* element = nullptr;

            TreeSignalWrapper() = default;
            ~TreeSignalWrapper() = default;

            void button_clicked(godot::TreeItem* item, int column, int id, int mouse_button_index);
            void cell_selected();
            void check_propagated_to_item(godot::TreeItem* item, int column);
            void column_title_clicked(int column, int mouse_button_index);
            void custom_item_clicked(int column);
            void custom_popup_edited(bool arrow_clicked);
            void empty_clicked(const Vector2& click_position, int mouse_button_index);
            void item_activated();
            void item_collapsed(godot::TreeItem* item);
            void item_edited();
            void item_icon_double_clicked();
            void item_mouse_selected(const Vector2& mouse_position, int mouse_button_index);
            void item_selected();
            void multi_selected(godot::TreeItem* item, int column, bool selected);
            void nothing_selected();
    };

    class Tree : public Control {
        private:
            GodotTree* tree = nullptr; // Pointer to the Tree instance

            TreeSignalWrapper* treeSignalWrapper = nullptr;
            void connectSignals() {
                if (this->treeSignalWrapper == nullptr) {
                    this->treeSignalWrapper = memnew(TreeSignalWrapper);
                    this->treeSignalWrapper->element = this;
                }

                this->tree->connect("button_clicked", Callable(this->treeSignalWrapper, "button_clicked"));
                this->tree->connect("cell_selected", Callable(this->treeSignalWrapper, "cell_selected"));
                this->tree->connect("check_propagated_to_item", Callable(this->treeSignalWrapper, "check_propagated_to_item"));
                this->tree->connect("column_title_clicked", Callable(this->treeSignalWrapper, "column_title_clicked"));
                this->tree->connect("custom_item_clicked", Callable(this->treeSignalWrapper, "custom_item_clicked"));
                this->tree->connect("custom_popup_edited", Callable(this->treeSignalWrapper, "custom_popup_edited"));
                this->tree->connect("empty_clicked", Callable(this->treeSignalWrapper, "empty_clicked"));
                this->tree->connect("item_activated", Callable(this->treeSignalWrapper, "item_activated"));
                this->tree->connect("item_collapsed", Callable(this->treeSignalWrapper, "item_collapsed"));
                this->tree->connect("item_edited", Callable(this->treeSignalWrapper, "item_edited"));
                this->tree->connect("item_icon_double_clicked", Callable(this->treeSignalWrapper, "item_icon_double_clicked"));
                this->tree->connect("item_mouse_selected", Callable(this->treeSignalWrapper, "item_mouse_selected"));
                this->tree->connect("item_selected", Callable(this->treeSignalWrapper, "item_selected"));
                this->tree->connect("multi_selected", Callable(this->treeSignalWrapper, "multi_selected"));
                this->tree->connect("nothing_selected", Callable(this->treeSignalWrapper, "nothing_selected"));
            }
        public:
            // Constructor with GodotTree parameter
            Tree(GodotTree* t) {
                setTree(t);
            }

            // Constructor with no parameters
            Tree() {
                setTree(memnew(GodotTree));
                onInit();
            }

            // Getter for the Tree node
            GodotTree* getTree() const {
                return tree;
            }

            // Setter for the Tree node
            void setTree(GodotTree* t) {
                tree = t;
                connectSignals();
                setControl(t);
            }

            bool getAllowReselect() const {
                return tree->get_allow_reselect();
            }

            void setAllowReselect(bool allow) {
                tree->set_allow_reselect(allow);
            }

            bool getAllowRmbSelect() const {
                return tree->get_allow_rmb_select();
            }

            void setAllowRmbSelect(bool allow) {
                tree->set_allow_rmb_select(allow);
            }

            bool getAllowSearch() const {
                return tree->get_allow_search();
            }

            void setAllowSearch(bool allow) {
                tree->set_allow_search(allow);
            }

            bool getAutoTooltip() const {
                return tree->is_auto_tooltip_enabled();
            }

            void setAutoTooltip(bool enable) {
                tree->set_auto_tooltip(enable);
            }

            bool getClipContents() const {
                return tree->is_clipping_contents();
            }

            void setClipContents(bool enabled) {
                tree->set_clip_contents(enabled);
            }

            bool getColumnTitlesVisible() const {
                return tree->are_column_titles_visible();
            }

            void setColumnTitlesVisible(bool visible) {
                tree->set_column_titles_visible(visible);
            }

            int getColumns() const {
                return tree->get_columns();
            }

            void setColumns(int amount) {
                tree->set_columns(amount);
            }

            int getDropModeFlags() const {
                return tree->get_drop_mode_flags();
            }

            void setDropModeFlags(int flags) {
                tree->set_drop_mode_flags(flags);
            }

            bool getEnableRecursiveFolding() const {
                return tree->is_recursive_folding_enabled();
            }

            void setEnableRecursiveFolding(bool enable) {
                tree->set_enable_recursive_folding(enable);
            }

            int getFocusMode() const {
                return tree->get_focus_mode();
            }

            void setFocusMode(int mode) {
                tree->set_focus_mode(static_cast<ControlNode::FocusMode>(mode));
            }

            bool getHideFolding() const {
                return tree->is_folding_hidden();
            }

            void setHideFolding(bool hide) {
                tree->set_hide_folding(hide);
            }

            bool getHideRoot() const {
                return tree->is_root_hidden();
            }

            void setHideRoot(bool enable) {
                tree->set_hide_root(enable);
            }

            bool getScrollHorizontalEnabled() const {
                return tree->is_h_scroll_enabled();
            }

            void setScrollHorizontalEnabled(bool enable) {
                tree->set_h_scroll_enabled(enable);
            }

            bool getScrollVerticalEnabled() const {
                return tree->is_v_scroll_enabled();
            }

            void setScrollVerticalEnabled(bool enable) {
                tree->set_v_scroll_enabled(enable);
            }

            int getSelectMode() const {
                return tree->get_select_mode();
            }

            void setSelectMode(int mode) {
                tree->set_select_mode(static_cast<GodotTree::SelectMode>(mode));
            }

            Event* buttonClickedEvent = new Event();
            Event* getButtonClickedEvent() {
                return buttonClickedEvent;
            }
            void setButtonClickedEvent(Event* event) {
                buttonClickedEvent = event;
            }

            Event* cellSelectedEvent = new Event();
            Event* getCellSelectedEvent() {
                return cellSelectedEvent;
            }
            void setCellSelectedEvent(Event* event) {
                cellSelectedEvent = event;
            }

            Event* checkPropagatedToItemEvent = new Event();
            Event* getCheckPropagatedToItemEvent() {
                return checkPropagatedToItemEvent;
            }
            void setCheckPropagatedToItemEvent(Event* event) {
                checkPropagatedToItemEvent = event;
            }

            Event* columnTitleClickedEvent = new Event();
            Event* getColumnTitleClickedEvent() {
                return columnTitleClickedEvent;
            }
            void setColumnTitleClickedEvent(Event* event) {
                columnTitleClickedEvent = event;
            }

            Event* customItemClickedEvent = new Event();
            Event* getCustomItemClickedEvent() {
                return customItemClickedEvent;
            }
            void setCustomItemClickedEvent(Event* event) {
                customItemClickedEvent = event;
            }

            Event* customPopupEditedEvent = new Event();
            Event* getCustomPopupEditedEvent() {
                return customPopupEditedEvent;
            }
            void setCustomPopupEditedEvent(Event* event) {
                customPopupEditedEvent = event;
            }

            Event* emptyClickedEvent = new Event();
            Event* getEmptyClickedEvent() {
                return emptyClickedEvent;
            }
            void setEmptyClickedEvent(Event* event) {
                emptyClickedEvent = event;
            }

            Event* itemActivatedEvent = new Event();
            Event* getItemActivatedEvent() {
                return itemActivatedEvent;
            }
            void setItemActivatedEvent(Event* event) {
                itemActivatedEvent = event;
            }

            Event* itemCollapsedEvent = new Event();
            Event* getItemCollapsedEvent() {
                return itemCollapsedEvent;
            }
            void setItemCollapsedEvent(Event* event) {
                itemCollapsedEvent = event;
            }

            Event* itemEditedEvent = new Event();
            Event* getItemEditedEvent() {
                return itemEditedEvent;
            }
            void setItemEditedEvent(Event* event) {
                itemEditedEvent = event;
            }

            Event* itemIconDoubleClickedEvent = new Event();
            Event* getItemIconDoubleClickedEvent() {
                return itemIconDoubleClickedEvent;
            }
            void setItemIconDoubleClickedEvent(Event* event) {
                itemIconDoubleClickedEvent = event;
            }

            Event* itemMouseSelectedEvent = new Event();
            Event* getItemMouseSelectedEvent() {
                return itemMouseSelectedEvent;
            }
            void setItemMouseSelectedEvent(Event* event) {
                itemMouseSelectedEvent = event;
            }

            Event* itemSelectedEvent = new Event();
            Event* getItemSelectedEvent() {
                return itemSelectedEvent;
            }
            void setItemSelectedEvent(Event* event) {
                itemSelectedEvent = event;
            }

            Event* multiSelectedEvent = new Event();
            Event* getMultiSelectedEvent() {
                return multiSelectedEvent;
            }
            void setMultiSelectedEvent(Event* event) {
                multiSelectedEvent = event;
            }

            Event* nothingSelectedEvent = new Event();
            Event* getNothingSelectedEvent() {
                return nothingSelectedEvent;
            }
            void setNothingSelectedEvent(Event* event) {
                nothingSelectedEvent = event;
            }

            void clear() {
                tree->clear();
            }

            TreeItem* createItem(TreeItem* parent = nullptr, int index = -1) {
                godot::TreeItem* parentItem = parent ? parent->getTreeItem() : nullptr;
                return new TreeItem(tree->create_item(parentItem, index));
            }

            void deselectAll() {
                tree->deselect_all();
            }

            bool editSelected(bool forceEdit = false) {
                return tree->edit_selected(forceEdit);
            }

            void ensureCursorIsVisible() {
                tree->ensure_cursor_is_visible();
            }

            int getButtonIdAtPosition(const Vector2& position) const {
                return tree->get_button_id_at_position(position);
            }

            int getColumnAtPosition(const Vector2& position) const {
                return tree->get_column_at_position(position);
            }

            int getColumnExpandRatio(int column) const {
                return tree->get_column_expand_ratio(column);
            }

            std::string getColumnTitle(int column) const {
                return tree->get_column_title(column).utf8().get_data();
            }

            int getColumnTitleAlignment(int column) const {
                return tree->get_column_title_alignment(column);
            }

            int getColumnTitleDirection(int column) const {
                return tree->get_column_title_direction(column);
            }

            std::string getColumnTitleLanguage(int column) const {
                return tree->get_column_title_language(column).utf8().get_data();
            }

            int getColumnWidth(int column) const {
                return tree->get_column_width(column);
            }

            Rect2 getCustomPopupRect() const {
                return tree->get_custom_popup_rect();
            }

            int getDropSelectionAtPosition(const Vector2& position) const {
                return tree->get_drop_section_at_position(position);
            }

            TreeItem* getEdited() const {
                return new TreeItem(tree->get_edited());
            }

            int getEditedColumn() const {
                return tree->get_edited_column();
            }

            Rect2 getItemAreaRect(TreeItem* item, int column = -1, int buttonIndex = -1) const {
                if (!item) {
                    return Rect2(); // Return an empty Rect2 if item is null
                }
                godot::TreeItem* treeItem = item ? item->getTreeItem() : nullptr;
                return tree->get_item_area_rect(treeItem, column, buttonIndex);
            }

            TreeItem* getItemAtPosition(const Vector2& position) const {
                return new TreeItem(tree->get_item_at_position(position));
            }

            TreeItem* getNextSelected(TreeItem* from) const {
                if (!from) {
                    return nullptr; // Avoid null pointer dereference
                }
                return new TreeItem(tree->get_next_selected(from->getTreeItem()));
            }

            int getPressedButton() const {
                return tree->get_pressed_button();
            }

            TreeItem* getRoot() const {
                return new TreeItem(tree->get_root());
            }

            Vector2 getScroll() const {
                return tree->get_scroll();
            }

            TreeItem* getSelected() const {
                return new TreeItem(tree->get_selected());
            }

            int getSelectedColumn() const {
                return tree->get_selected_column();
            }

            bool isColumnClippingContent(int column) const {
                return tree->is_column_clipping_content(column);
            }

            bool isColumnExpanding(int column) const {
                return tree->is_column_expanding(column);
            }

            void scrollToItem(TreeItem* item, bool centerOnItem = false) {
                if (!item) {
                    return; // Avoid null pointer dereference
                }
                godot::TreeItem* treeItem = item ? item->getTreeItem() : nullptr;
                tree->scroll_to_item(treeItem, centerOnItem);
            }

            void setColumnCustomMinimumWidth(int column, int minWidth) {
                tree->set_column_custom_minimum_width(column, minWidth);
            }

            void setColumnExpand(int column, bool expand) {
                tree->set_column_expand(column, expand);
            }

            void setColumnExpandRatio(int column, int ratio) {
                tree->set_column_expand_ratio(column, ratio);
            }

            void setColumnTitle(int column, const std::string& title) {
                tree->set_column_title(column, String(title.c_str()));
            }

            void setColumnTitleAlignment(int column, int alignment) {
                tree->set_column_title_alignment(column, static_cast<HorizontalAlignment>(alignment));
            }

            void setColumnTitleDirection(int column, int direction) {
                tree->set_column_title_direction(column, static_cast<ControlNode::TextDirection>(direction));
            }

            void setColumnTitleLanguage(int column, const std::string& language) {
                tree->set_column_title_language(column, String(language.c_str()));
            }

            void setSelected(TreeItem* item, int column) {
                if (!item) {
                    return; // Avoid null pointer dereference
                }
                tree->set_selected(item->getTreeItem(), column);
            }

            void onFree() override {
                if (treeSignalWrapper) {
                    memdelete(treeSignalWrapper);
                    treeSignalWrapper = nullptr;
                }
                Control::onFree();
            }
    };
}

#endif // TREE_H
