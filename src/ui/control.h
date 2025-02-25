#ifndef CONTROL_H
#define CONTROL_H

#include <godot_cpp/classes/control.hpp>

#define ControlNode godot::Control

#include "canvas_item.h"

namespace sunaba::ui {
    void bindControl(sol::state &lua);

    class Control : public CanvasItem {
    private:
        ControlNode* control = nullptr; // Pointer to the Control instance
    protected:
        // Constructor with Node* parameter
        Control(ControlNode* p_node) : CanvasItem(p_node), control(p_node) {
            onInit();
        }
    
    public:
        // Constructor with no parameters
        Control() : CanvasItem(new ControlNode()) {
            control = static_cast<ControlNode*>(getNode());
            onInit();
        }

        // Getter for the Control node
        ControlNode* getControl() {
            return control;
        }

        // Setter for the Control node
        void setControl(ControlNode* p_node) {
            control = p_node;
            setNode(control);
        }

        float getAnchorBottom() {
            return control->get_anchor(godot::Side::SIDE_BOTTOM);
        }

        void setAnchorBottom(float anchor_bottom) {
            control->set_anchor(godot::Side::SIDE_BOTTOM, anchor_bottom);
        }

        float getAnchorLeft() {
            return control->get_anchor(godot::Side::SIDE_LEFT);
        }

        void setAnchorLeft(float anchor_left) {
            control->set_anchor(godot::Side::SIDE_LEFT, anchor_left);
        }

        float getAnchorRight() {
            return control->get_anchor(godot::Side::SIDE_RIGHT);
        }

        void setAnchorRight(float anchor_right) {
            control->set_anchor(godot::Side::SIDE_RIGHT, anchor_right);
        }

        float getAnchorTop() {
            return control->get_anchor(godot::Side::SIDE_TOP);
        }

        void setAnchorTop(float anchor_top) {
            control->set_anchor(godot::Side::SIDE_TOP, anchor_top);
        }

        bool isClipContentsEnabled() {
            return control->is_clipping_contents();
        }

        void setClipContents(bool enabled) {
            control->set_clip_contents(enabled);
        }

        Vector2 getCustomMinimumSize() {
            return control->get_custom_minimum_size();
        }

        void setCustomMinimumSize(Vector2 size) {
            control->set_custom_minimum_size(size);
        }

        int getFocusMode() {
            return control->get_focus_mode();
        }

        void setFocusMode(int mode) {
            control->set_focus_mode(static_cast<ControlNode::FocusMode>(mode));
        }

        std::string getFocusNeighborBottom() {
            return String(control->get_focus_neighbor(godot::Side::SIDE_BOTTOM).get_concatenated_names()).utf8().get_data();
        }

        void setFocusNeighborBottom(std::string name) {
            control->set_focus_neighbor(godot::Side::SIDE_BOTTOM, NodePath(name.c_str()));
        }

        std::string getFocusNeighborLeft() {
            return String(control->get_focus_neighbor(godot::Side::SIDE_LEFT).get_concatenated_names()).utf8().get_data();
        }

        void setFocusNeighborLeft(std::string name) {
            control->set_focus_neighbor(godot::Side::SIDE_LEFT, NodePath(name.c_str()));
        }

        std::string getFocusNeighborRight() {
            return String(control->get_focus_neighbor(godot::Side::SIDE_RIGHT).get_concatenated_names()).utf8().get_data();
        }

        void setFocusNeighborRight(std::string name) {
            control->set_focus_neighbor(godot::Side::SIDE_RIGHT, NodePath(name.c_str()));
        }

        std::string getFocusNeighborTop() {
            return String(control->get_focus_neighbor(godot::Side::SIDE_TOP).get_concatenated_names()).utf8().get_data();
        }

        void setFocusNeighborTop(std::string name) {
            control->set_focus_neighbor(godot::Side::SIDE_TOP, NodePath(name.c_str()));
        }

        std::string getFoucsNext() {
            return String(control->get_focus_next().get_concatenated_names()).utf8().get_data();
        }

        void setFocusNext(std::string name) {
            control->set_focus_next(NodePath(name.c_str()));
        }
        
        std::string getFocusPrevious() {
            return String(control->get_focus_previous().get_concatenated_names()).utf8().get_data();
        }

        void setFocusPrevious(std::string name) {
            control->set_focus_previous(NodePath(name.c_str()));
        }

        Vector2 getGlobalPosition() {
            return control->get_global_position();
        }

        void setGlobalPosition(Vector2 position) {
            control->set_global_position(position);
        }

        int getGrowHorizontal() {
            return control->get_h_grow_direction();
        }

        void setGrowHorizontal(int direction) {
            control->set_h_grow_direction(static_cast<ControlNode::GrowDirection>(direction));
        }

        int getGrowVertical() {
            return control->get_v_grow_direction();
        }

        void setGrowVertical(int direction) {
            control->set_v_grow_direction(static_cast<ControlNode::GrowDirection>(direction));
        }

        int getLayoutDirection() {
            return control->get_layout_direction();
        }

        void setLayoutDirection(int direction) {
            control->set_layout_direction(static_cast<ControlNode::LayoutDirection>(direction));
        }
    };
}

#endif // CONTROL_H