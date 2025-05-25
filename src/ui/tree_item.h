#ifndef TREE_ITEM_H
#define TREE_ITEM_H

#include <godot_cpp/classes/tree_item.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTreeItem godot::TreeItem

#include "../core/base_object.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTreeItem(sol::state& lua);

    class TreeItem : public BaseObject {
        private:
            GodotTreeItem* tree_item = nullptr; // Pointer to the TreeItem instance
        public:
            // Constructor with GodotTreeItem parameter
            TreeItem(GodotTreeItem* item) {
                setTreeItem(item);
            }

            // Constructor with no parameters
            TreeItem() {
                tree_item = memnew(GodotTreeItem);
            }

            // Getter for the TreeItem node
            GodotTreeItem* getTreeItem() const {
                return tree_item;
            }

            // Setter for the TreeItem node
            void setTreeItem(GodotTreeItem* item) {
                tree_item = item;
            }

            bool getCollapsed() const {
                return tree_item->is_collapsed();
            }

            void setCollapsed(bool collapsed) {
                tree_item->set_collapsed(collapsed);
            }

            int getCustomMinimumHeight() const {
                return tree_item->get_custom_minimum_height();
            }

            bool getDisableFolding() const {
                return tree_item->is_folding_disabled();
            }

            void setDisableFolding(bool disable) {
                tree_item->set_folding_disabled(disable);
            }

            bool getVisible() const {
                return tree_item->is_visible();
            }

            void setVisible(bool visible) {
                tree_item->set_visible(visible);
            }
    };
}


#endif // TREE_ITEM_H