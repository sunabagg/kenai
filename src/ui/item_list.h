#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include <godot_cpp/classes/item_list.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ItemListNode godot::ItemList

#include "control.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindItemList(sol::state &lua);

    class ItemList;

    class ItemListProxy : public ItemListNode {
        public:
            sunaba::ui::ItemList* element = nullptr;

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
            
            void _gui_input(const Ref<InputEvent>& event) override;
            bool _has_point(const Vector2 &point) const override;
            String _get_tooltip(const Vector2 &at_position) const override;
            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
        };

        class ItemList : public Control {
        private:
            ItemListNode* item_list = nullptr; // Pointer to the ItemList instance

            void connectItemListSignals() {
                // Connect signals from the item list to the element
                // Example: item_list->connect("signal_name", this, "method_name");
            }

        public:
            ItemList() {
                setItemList(memnew(ItemListProxy));
                onInit();
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
    };
}

#endif // ITEM_LIST_H