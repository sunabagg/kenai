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
    };
}

#endif // CONTROL_H