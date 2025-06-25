#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <godot_cpp/classes/button_group.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotButtonGroup godot::ButtonGroup

#include "../core/resource.h"
#include "../core/event.h"
#include "../core/stl_function_wrapper.h"

using namespace lucidware::core;

namespace lucidware::ui {

    class BaseButton;

    void bindButtonGroup(sol::state &lua);

    class ButtonGroup : public lucidware::core::Resource {
    private:
        GodotButtonGroup* button_group = nullptr; // Pointer to the ButtonGroup instance

        void connectButtonGroupSignals() {
            // Connect signals specific to ButtonGroup
            std::function<Variant(std::vector<Variant>)> pressedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->pressed != nullptr) {
                        this->pressed->emit(args);
                    }
                    return Variant();
                };
            Callable pressedCallable = StlFunctionWrapper::create_callable_from_cpp_function(pressedFunc);
            button_group->connect("pressed", pressedCallable);
        }
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

        bool isAllowUnpress() {
            return button_group->is_allow_unpress();
        }

        void setAllowUnpress(bool p_enabled) {
            button_group->set_allow_unpress(p_enabled);
        }

        Event* pressed;

        std::vector<BaseButton*> getButtons();

        BaseButton* getPressedButton();
    };
}

#endif // BUTTONGROUP_H