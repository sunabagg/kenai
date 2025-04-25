#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <godot_cpp/classes/button_group.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotButtonGroup godot::ButtonGroup

#include "../core/resource.h"

namespace sunaba::ui {

    class BaseButton;

    void bindButtonGroup(sol::state &lua);

    class ButtonGroup : public sunaba::core::Resource {
    private:
        GodotButtonGroup* button_group = nullptr; // Pointer to the ButtonGroup instance
    public:
        // Constructor with Node* parameter
        ButtonGroup(GodotButtonGroup* p_node) {
            setButtonGroup(p_node);
        }

        // Constructor with no parameters
        ButtonGroup() {
            setButtonGroup(memnew(GodotButtonGroup));
        }

        // Getter for the ButtonGroup node
        GodotButtonGroup* getButtonGroup() {
            return button_group;
        }

        // Setter for the ButtonGroup node
        void setButtonGroup(GodotButtonGroup* p_node) {
            button_group = p_node;
            setResource(button_group);
        }
    };
}

#endif // BUTTONGROUP_H