#ifndef STYLE_BOX_EMPTY_H
#define STYLE_BOX_EMPTY_H

#include <godot_cpp/classes/style_box_empty.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotStyleBoxEmpty godot::StyleBoxEmpty

#include "style_box.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::ui {
    void bindStyleBoxEmpty(sol::state &lua);

    class StyleBoxEmpty : public lucidfx::ui::StyleBox {
    private:
        GodotStyleBoxEmpty* style_box_empty = nullptr; // Pointer to the StyleBox instance
    public:
        // Constructor with Node* parameter
        StyleBoxEmpty(GodotStyleBoxEmpty* p_node) {
            setStyleBoxEmpty(p_node);
        }
    
        // Constructor with no parameters
        StyleBoxEmpty() {
            setStyleBoxEmpty(memnew(GodotStyleBoxEmpty));
        }

        // Getter for the StyleBox node
        GodotStyleBoxEmpty* getStyleBoxEmpty() {
            return style_box_empty;
        }

        // Setter for the StyleBox node
        void setStyleBoxEmpty(GodotStyleBoxEmpty* p_node) {
            style_box_empty = p_node;
            setStyleBox(style_box_empty);
        }
    };
}

#endif // STYLE_BOX_EMPTY_H