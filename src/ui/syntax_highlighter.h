#ifndef SYNTAX_HIGHLIGHTER_H
#define SYNTAX_HIGHLIGHTER_H

#include <godot_cpp/classes/syntax_highlighter.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotSyntaxHighlighter godot::SyntaxHighlighter

#include "../core/resource.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindSyntaxHighlighter(sol::state &lua);

    class SyntaxHighlighter : public sunaba::core::Resource {
    private:
        GodotSyntaxHighlighter* syntax_highlighter = nullptr; // Pointer to the SyntaxHighlighter instance
    public:
        // Constructor with Node* parameter
        SyntaxHighlighter(GodotSyntaxHighlighter* p_node) {
            setSyntaxHighlighter(p_node);
        }
    
        // Constructor with no parameters
        SyntaxHighlighter() {
            setSyntaxHighlighter(memnew(GodotSyntaxHighlighter));
        }

        // Getter for the SyntaxHighlighter node
        GodotSyntaxHighlighter* getSyntaxHighlighter() const {
            return syntax_highlighter;
        }

        // Setter for the SyntaxHighlighter node
        void setSyntaxHighlighter(GodotSyntaxHighlighter* p_node) {
            syntax_highlighter = p_node;
            setResource(syntax_highlighter);
        }
    };
}

#endif // SYNTAX_HIGHLIGHTER_H