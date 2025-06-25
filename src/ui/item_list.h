#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include <godot_cpp/classes/item_list.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ItemListNode godot::ItemList

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "../core/texture2d.h"
#include "h_scroll_bar.h"
#include "v_scroll_bar.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::ui {
    void bindItemList(sol::state &lua);

    class ItemList;

    class ItemListProxy : public ItemListNode {
        GDCLASS(ItemListProxy, ItemListNode)
        protected:
            static void _bind_methods() {}
        public:
            lucidware::ui::ItemList* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
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

        class ItemListSignalWrapper : public Object {
            GDCLASS(ItemListSignalWrapper, Object)
            protected:
                static void _bind_methods();
            public:
                ItemList* element = nullptr;

                ItemListSignalWrapper() = default;
                ~ItemListSignalWrapper() = default;

                void emptyClicked(const Vector2 &at_position, int button_index);
                void itemActivated(int index);
                void itemClicked(int index, const Vector2 &at_position, int button_index);
                void itemSelected(int index);
                void multiSelected(int index, bool selected);
        };

        class ItemList : public Control {
        private:
            ItemListNode* item_list = nullptr; // Pointer to the ItemList instance

            ItemListSignalWrapper* item_list_signal_wrapper = nullptr;
            void connectItemListSignals() {
                // Connect signals from the item list to the element
                // Example: item_list->connect("signal_name", this, "method_name");
                if (this->item_list_signal_wrapper == nullptr) {
                    this->item_list_signal_wrapper = memnew(ItemListSignalWrapper);
                    this->item_list_signal_wrapper->element = this;
                }

                this->item_list->connect("empty_clicked", Callable(this->item_list_signal_wrapper, "emptyClicked"));
                this->item_list->connect("item_activated", Callable(this->item_list_signal_wrapper, "itemActivated"));
                this->item_list->connect("item_clicked", Callable(this->item_list_signal_wrapper, "itemClicked"));
                this->item_list->connect("item_selected", Callable(this->item_list_signal_wrapper, "itemSelected"));
                this->item_list->connect("multi_selected", Callable(this->item_list_signal_wrapper, "multiSelected"));
            }

        public:
            ItemList() {
                setItemList(memnew(ItemListNode));
                onInit();
            }

            ItemList(ItemListNode* item_list) {
                setItemList(item_list);
            }

            ItemListNode* getItemList() {
                return item_list;
            }

            void setItemList(ItemListNode* node) {
                item_list = node;
                connectItemListSignals();
                setControl(item_list);
            }

            void setItemListProxy(ItemListProxy* node) {
                item_list = node;
                node->element = this;
                connectItemListSignals();
                setControl(item_list);
            }

            bool getAllowReselect() {
                return item_list->get_allow_reselect();
            }

            void setAllowReselect(bool allow) {
                item_list->set_allow_reselect(allow);
            }

            bool getAllowRmbSelect() {
                return item_list->get_allow_rmb_select();
            }

            void setAllowRmbSelect(bool allow) {
                item_list->set_allow_rmb_select(allow);
            }

            bool getAllowSearch() {
                return item_list->get_allow_search();
            }

            void setAllowSearch(bool allow) {
                item_list->set_allow_search(allow);
            }

            bool getAutoHeight() {
                return item_list->has_auto_height();
            }

            void setAutoHeight(bool enable) {
                item_list->set_auto_height(enable);
            }

            bool getAutoWidth() {
                return item_list->has_auto_width();
            }

            void setAutoWidth(bool enable) {
                item_list->set_auto_width(enable);
            }

            bool getClipContents() {
                return item_list->is_clipping_contents();
            }

            void setClipContents(bool enable) {
                item_list->set_clip_contents(enable);
            }

            int getFixedColumnWidth() {
                return item_list->get_fixed_column_width();
            }

            void setFixedColumnWidth(int width) {
                item_list->set_fixed_column_width(width);
            }

            Vector2i getFixedIconSize() {
                return item_list->get_fixed_icon_size();
            }

            void setFixedIconSize(Vector2i size) {
                item_list->set_fixed_icon_size(size);
            }

            int getFocusMode() {
                return item_list->get_focus_mode();
            }

            void setFocusMode(int mode) {
                item_list->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            int getIconMode() {
                return item_list->get_icon_mode();
            }

            void setIconMode(int mode) {
                item_list->set_icon_mode(static_cast<godot::ItemList::IconMode>(mode));
            }

            float getIconScale() {
                return item_list->get_icon_scale();
            }

            void setIconScale(float scale) {
                item_list->set_icon_scale(scale);
            }

            int getItemCount() {
                return item_list->get_item_count();
            }

            void setItemCount(int count) {
                item_list->set_item_count(count);
            }

            int getMaxColumns() {
                return item_list->get_max_columns();
            }

            void setMaxColumns(int columns) {
                item_list->set_max_columns(columns);
            }

            int getMaxTextLines() {
                return item_list->get_max_text_lines();
            }

            void setMaxTextLines(int lines) {
                item_list->set_max_text_lines(lines);
            }

            bool getSameColumnWidth() {
                return item_list->is_same_column_width();
            }

            void setSameColumnWidth(bool enable) {
                item_list->set_same_column_width(enable);
            }

            int getSelectMode() {
                return item_list->get_select_mode();
            }

            void setSelectMode(int mode) {
                item_list->set_select_mode(static_cast<godot::ItemList::SelectMode>(mode));
            }

            int getTextOverrunBehavior() {
                return item_list->get_text_overrun_behavior();
            }

            void setTextOverrunBehavior(int behavior) {
                item_list->set_text_overrun_behavior(static_cast<godot::TextServer::OverrunBehavior>(behavior));
            }

            bool getWraparoundItems() {
                return item_list->has_wraparound_items();
            }

            void setWraparoundItems(bool enable) {
                item_list->set_wraparound_items(enable);
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
            Event* itemClickedEvent = new Event();
            Event* getItemClickedEvent() {
                return itemClickedEvent;
            }
            void setItemClickedEvent(Event* event) {
                itemClickedEvent = event;
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

            int addIconItem(lucidware::core::Texture2D* texture, bool selectable = true) {
                Ref<godot::Texture2D> textureRef = Ref<godot::Texture2D>(texture->getTexture());
                return item_list->add_icon_item(textureRef, selectable);
            }

            int addItem(std::string text, lucidware::core::Texture2D* icon = nullptr, bool selectable = true) {
                Ref<godot::Texture2D> textureRef;
                if (icon != nullptr) {
                    textureRef = Ref<godot::Texture2D>(icon->getTexture());
                }
                return item_list->add_item(text.c_str(), textureRef, selectable);
            }

            void clear() {
                item_list->clear();
            }

            void deselect(int index) {
                item_list->deselect(index);
            }

            void deselectAll() {
                item_list->deselect_all();
            }

            void ensureCurrentIsVisible() {
                item_list->ensure_current_is_visible();
            }

            void forceUpdateListSize() {
                item_list->force_update_list_size();
            }

            HScrollBar* getHScrollBar() {
                return new HScrollBar(item_list->get_h_scroll_bar());
            }

            int getItemAtPosition(Vector2 position, bool exact = false) {
                return item_list->get_item_at_position(position, exact);
            }

            int getItemAutoTranslateMode(int index) {
                return item_list->get_item_auto_translate_mode(index);
            }

            Color getItemCustomBgColor(int index) {
                return item_list->get_item_custom_bg_color(index);
            }

            Color getItemCustomFgColor(int index) {
                return item_list->get_item_custom_fg_color(index);
            }

            lucidware::core::Texture2D* getItemIcon(int index) {
                Ref<godot::Texture2D> textureRef = item_list->get_item_icon(index);
                return new lucidware::core::Texture2D(textureRef.ptr());
            }

            Color getItemIconModulate(int index) {
                return item_list->get_item_icon_modulate(index);
            }

            Rect2 getItemIconRegion(int index) {
                return item_list->get_item_icon_region(index);
            }

            std::string getItemLanguage(int index) {
                return item_list->get_item_language(index).utf8().get_data();
            }

            Variant getItemMetadata(int index) {
                return item_list->get_item_metadata(index);
            }

            Rect2 getItemRect(int index) {
                return item_list->get_item_rect(index);
            }

            std::string getItemText(int index) {
                return item_list->get_item_text(index).utf8().get_data();
            }

            int getItemTextDirection(int index) {
                return item_list->get_item_text_direction(index);
            }

            std::string getItemTooltip(int index) {
                return item_list->get_item_tooltip(index).utf8().get_data();
            }

            std::vector<int> getSelectedItems() {
                PackedInt32Array selectedItems = item_list->get_selected_items();
                std::vector<int> result;
                for (int i = 0; i < selectedItems.size(); i++) {
                    result.push_back(selectedItems[i]);
                }
                return result;
            }

            VScrollBar* getVScrollBar() {
                return new VScrollBar(item_list->get_v_scroll_bar());
            }

            bool isAnythingSelected() {
                return item_list->is_anything_selected();
            }

            bool isItemDisabled(int index) {
                return item_list->is_item_disabled(index);
            }

            bool isItemIconTransposed(int index) {
                return item_list->is_item_icon_transposed(index);
            }

            bool isItemSelectable(int index) {
                return item_list->is_item_selectable(index);
            }

            bool isItemTooltipEnabled(int index) {
                return item_list->is_item_tooltip_enabled(index);
            }

            bool isSelected(int index) {
                return item_list->is_selected(index);
            }

            void moveItem(int fromIndex, int toIndex) {
                item_list->move_item(fromIndex, toIndex);
            }

            void removeItem(int index) {
                item_list->remove_item(index);
            }

            void select(int index, bool single = true) {
                item_list->select(index, single);
            }

            void setItemAutoTranslateMode(int index, int mode) {
                item_list->set_item_auto_translate_mode(index, static_cast<godot::Node::AutoTranslateMode>(mode));
            }

            void setItemCustomBgColor(int index, Color color) {
                item_list->set_item_custom_bg_color(index, color);
            }

            void setItemCustomFgColor(int index, Color color) {
                item_list->set_item_custom_fg_color(index, color);
            }

            void setItemDisabled(int index, bool disabled) {
                item_list->set_item_disabled(index, disabled);
            }

            void setItemIcon(int index, lucidware::core::Texture2D* texture) {
                Ref<godot::Texture2D> textureRef = Ref<godot::Texture2D>(texture->getTexture());
                item_list->set_item_icon(index, textureRef);
            }

            void setItemIconModulate(int index, Color color) {
                item_list->set_item_icon_modulate(index, color);
            }

            void setItemIconRegion(int index, Rect2 rect) {
                item_list->set_item_icon_region(index, rect);
            }

            void setItemIconTransposed(int index, bool transposed) {
                item_list->set_item_icon_transposed(index, transposed);
            }

            void setItemLanguage(int index, std::string language) {
                item_list->set_item_language(index, language.c_str());
            }

            void setItemMetadata(int index, Variant metadata) {
                item_list->set_item_metadata(index, metadata);
            }

            void setItemSelectable(int index, bool selectable) {
                item_list->set_item_selectable(index, selectable);
            }

            void setItemText(int index, std::string text) {
                item_list->set_item_text(index, text.c_str());
            }

            void setItemTextDirection(int index, int direction) {
                item_list->set_item_text_direction(index, static_cast<godot::Control::TextDirection>(direction));
            }

            void setItemTooltip(int index, std::string tooltip) {
                item_list->set_item_tooltip(index, tooltip.c_str());
            }

            void setItemTooltipEnabled(int index, bool enable) {
                item_list->set_item_tooltip_enabled(index, enable);
            }

            void sortItemsByText() {
                item_list->sort_items_by_text();
            }

            void onFree() override {
                if (item_list_signal_wrapper) {
                    memdelete(item_list_signal_wrapper);
                    item_list_signal_wrapper = nullptr;
                }
                Control::onFree();
            }
    };
}

#endif // ITEM_LIST_H