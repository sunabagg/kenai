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
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTree(sol::state& lua);

    class Tree;

    class TreeProxy : public GodotTree {
        public:
            sunaba::ui::Tree* element = nullptr;

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

    class Tree : public Control {
        private:
            GodotTree* tree = nullptr; // Pointer to the Tree instance

            void connectSignals() {
            }
        public:
            // Constructor with GodotTree parameter
            Tree(GodotTree* t) {
                setTree(t);
            }

            // Constructor with no parameters
            Tree() {
                setTree(memnew(TreeProxy));
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

            Event* buttonClickedEvent;
            Event* getButtonClickedEvent() {
                return buttonClickedEvent;
            }
            void setButtonClickedEvent(Event* event) {
                buttonClickedEvent = event;
            }

            Event* cellSelectedEvent;
            Event* getCellSelectedEvent() {
                return cellSelectedEvent;
            } 
            void setCellSelectedEvent(Event* event) {
                cellSelectedEvent = event;
            }

            Event* checkPropagatedToItemEvent;
            Event* getCheckPropagatedToItemEvent() {
                return checkPropagatedToItemEvent;
            }
            void setCheckPropagatedToItemEvent(Event* event) {
                checkPropagatedToItemEvent = event;
            }
            
            Event* columnTitleClickedEvent;
            Event* getColumnTitleClickedEvent() {
                return columnTitleClickedEvent;
            }
            void setColumnTitleClickedEvent(Event* event) {
                columnTitleClickedEvent = event;
            }

            Event* customItenClickedEvent;
            Event* getCustomItemClickedEvent() {
                return customItenClickedEvent;
            }
            void setCustomItemClickedEvent(Event* event) {
                customItenClickedEvent = event;
            }

            Event* customPopupEditedEvent;
            Event* getCustomPopupEditedEvent() {
                return customPopupEditedEvent;
            }
            void setCustomPopupEditedEvent(Event* event) {
                customPopupEditedEvent = event;
            }

            Event* emptyClickedEvent;
            Event* getEmptyClickedEvent() {
                return emptyClickedEvent;
            }
            void setEmptyClickedEvent(Event* event) {
                emptyClickedEvent = event;
            }

            Event* itemActivatedEvent;
            Event* getItemActivatedEvent() {
                return itemActivatedEvent;
            }
            void setItemActivatedEvent(Event* event) {
                itemActivatedEvent = event;
            }

            Event* itemCollapsedEvent;
            Event* getItemCollapsedEvent() {
                return itemCollapsedEvent;
            }
            void setItemCollapsedEvent(Event* event) {
                itemCollapsedEvent = event;
            }

            Event* itemEditedEvent;
            Event* getItemEditedEvent() {
                return itemEditedEvent;
            }
            void setItemEditedEvent(Event* event) {
                itemEditedEvent = event;
            }

            Event* itemIconDoubleClickedEvent;
            Event* getItemIconDoubleClickedEvent() {
                return itemIconDoubleClickedEvent;
            }
            void setItemIconDoubleClickedEvent(Event* event) {
                itemIconDoubleClickedEvent = event;
            }

            Event* itemMouseSelectedEvent;
            Event* getItemMouseSelectedEvent() {
                return itemMouseSelectedEvent;
            }
            void setItemMouseSelectedEvent(Event* event) {
                itemMouseSelectedEvent = event;
            }

            Event* itemSelectedEvent;
            Event* getItemSelectedEvent() {
                return itemSelectedEvent;
            }
            void setItemSelectedEvent(Event* event) {
                itemSelectedEvent = event;
            }

            Event* multiSelectedEvent;
            Event* getMultiSelectedEvent() {
                return multiSelectedEvent;
            }
            void setMultiSelectedEvent(Event* event) {
                multiSelectedEvent = event;
            }

            Event* nothingSelectedEvent;
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
                return new TreeItem(tree->create_item(parent->getTreeItem(), index));
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

            int getEditedColumn() const {
                return tree->get_edited_column();
            }

            Rect2 getItemAreaRect(TreeItem* item, int column = -1, int buttonIndex = -1) const {
                return tree->get_item_area_rect(item->getTreeItem(), column, buttonIndex);
            }
    };
}

#endif // TREE_H