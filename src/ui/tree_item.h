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
                tree_item->set_disable_folding(disable);
            }

            bool getVisible() const {
                return tree_item->is_visible();
            }

            void setVisible(bool visible) {
                tree_item->set_visible(visible);
            }

            void addButton(int column, sunaba::core::Texture2D* button, int id = -1, bool disabled = false, std::string toolTipText = "&quot;&quot;") {
                tree_item->add_button(column, Ref<godot::Texture2D>(button->getTexture2D()), id, disabled, toolTipText.c_str());
            }

            void addChild(TreeItem* child) {
                tree_item->add_child(child->getTreeItem());
            }
            
            void clearButtons() {
                tree_item->clear_buttons();
            }

            void clearCustomBgColor(int column) {
                tree_item->clear_custom_bg_color(column);
            }

            void clearCustomColor(int column) {
                tree_item->clear_custom_color(column);
            }

            TreeItem* createChild(int index = -1) {
                return new TreeItem(tree_item->create_child(index));
            }

            void deselect(int column) {
                tree_item->deselect(column);
            }

            void eraseButton(int column, int idx) {
                tree_item->erase_button(column, idx);
            }

            int getAutoTranslateMode(int column) const {
                return tree_item->get_auto_translate_mode(column);
            }

            sunaba::core::Texture2D* getButton(int column, int idx) const {
                return new sunaba::core::Texture2D(tree_item->get_button(column, idx).ptr());
            }

            int getButtonById(int column, int id) const {
                return tree_item->get_button_by_id(column, id);
            }

            Color getButtonColor(int column, int idx) const {
                return tree_item->get_button_color(column, idx);
            }

            int getButtonCount(int column) const {
                return tree_item->get_button_count(column);
            }
    };
}


#endif // TREE_ITEM_H