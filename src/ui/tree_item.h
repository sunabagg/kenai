#ifndef TREE_ITEM_H
#define TREE_ITEM_H

#include <godot_cpp/classes/tree_item.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotTreeItem godot::TreeItem

#include "../core/base_object.h"
#include "../core/texture2d.h"
#include "../core/font.h"

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

            int getButtonId(int column, int idx) const {
                return tree_item->get_button_id(column, idx);
            }

            std::string getButtonTooltipText(int column, int idx) const {
                return tree_item->get_button_tooltip_text(column, idx).utf8().get_data();
            }

            int getCellMode(int column) const {
                return tree_item->get_cell_mode(column);
            }

            TreeItem* getChild(int index) const {
                return new TreeItem(tree_item->get_child(index));
            }

            int getChildCount() const {
                return tree_item->get_child_count();
            }

            std::vector<TreeItem*> getChildren() const {
                std::vector<TreeItem*> children;
                for (int i = 0; i < tree_item->get_child_count(); ++i) {
                    children.push_back(new TreeItem(tree_item->get_child(i)));
                }
                return children;
            }

            Color getCustomBgColor(int column) const {
                return tree_item->get_custom_bg_color(column);
            }

            Color getCustomColor(int column) const {
                return tree_item->get_custom_color(column);
            }

            sunaba::core::Font* getCustomFont(int column) const {
                return new sunaba::core::Font(tree_item->get_custom_font(column).ptr());
            }

            int getCustomFontSize(int column) const {
                return tree_item->get_custom_font_size(column);
            }


            bool getExpandRight(int column) const {
                return tree_item->get_expand_right(column);
            }

            TreeItem* getFirstChild() const {
                return new TreeItem(tree_item->get_first_child());
            }

            sunaba::core::Texture2D* getIcon(int column) const {
                return new sunaba::core::Texture2D(tree_item->get_icon(column).ptr());
            }

            int getIconMaxWidth(int column) const {
                return tree_item->get_icon_max_width(column);
            }

            Color getIconModulate(int column) const {
                return tree_item->get_icon_modulate(column);
            }

            sunaba::core::Texture2D* getIconOverlay(int column) const {
                return new sunaba::core::Texture2D(tree_item->get_icon_overlay(column).ptr());
            }

            Rect2 getIconRegion(int column) const {
                return tree_item->get_icon_region(column);
            }
            
            int getIndex() const {
                return tree_item->get_index();
            }

            std::string getLanguage(int column) const {
                return tree_item->get_language(column).utf8().get_data();
            }

            Variant getMetadata(int column) const {
                return tree_item->get_metadata(column);
            }

            TreeItem* getNext() {
                return new TreeItem(tree_item->get_next());
            }

            TreeItem* getNextInTree() {
                return new TreeItem(tree_item->get_next_in_tree());
            }

            TreeItem* getNextVisible() {
                return new TreeItem(tree_item->get_next_visible());
            }

            TreeItem* getParent() const {
                return new TreeItem(tree_item->get_parent());
            }

            TreeItem* getPrev() {
                return new TreeItem(tree_item->get_prev());
            }

            TreeItem* getPrevInTree() {
                return new TreeItem(tree_item->get_prev_in_tree());
            }

            TreeItem* getPrevVisible() {
                return new TreeItem(tree_item->get_prev_visible());
            }

            float getRange(int column) const {
                return tree_item->get_range(column);
            }

            Dictionary getRangeConfig(int column) const {
                return tree_item->get_range_config(column);
            }

            int getStructuredTextBidiOverride(int column) const {
                return tree_item->get_structured_text_bidi_override(column);
            }

            Array getStructuredTextBidiOverrideOptions(int column) const {
                return tree_item->get_structured_text_bidi_override_options(column);
            }

            std::string getSuffix(int column) const {
                return tree_item->get_suffix(column).utf8().get_data();
            }

            std::string getText(int column) const {
                return tree_item->get_text(column).utf8().get_data();
            }

            int getTextAlignment(int column) const {
                return tree_item->get_text_alignment(column);
            }

            int getTextDirection(int column) const {
                return tree_item->get_text_direction(column);
            }

            int getTextOverrunBehavior(int column) const {
                return tree_item->get_text_overrun_behavior(column);
            }
    };
}


#endif // TREE_ITEM_H