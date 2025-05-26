#ifndef CODE_HIGHLIGHTER_H
#define CODE_HIGHLIGHTER_H

#include <godot_cpp/classes/code_highlighter.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCodeHighlighter godot::CodeHighlighter

#include "syntax_highlighter.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindCodeHighlighter(sol::state &lua);

    class CodeEdit;

    class CodeHighlighter : public sunaba::core::Resource {
    private:
        GodotCodeHighlighter* code_highlighter = nullptr; // Pointer to the CodeHighlighter instance
    public:
        // Constructor with Node* parameter
        CodeHighlighter(GodotCodeHighlighter* p_node) {
            setCodeHighlighter(p_node);
        }

        // Constructor with no parameters
        CodeHighlighter() {
            setCodeHighlighter(memnew(GodotCodeHighlighter));
        }

        // Getter for the CodeHighlighter node
        GodotCodeHighlighter* getCodeHighlighter() const {
            return code_highlighter;
        }

        // Setter for the CodeHighlighter node
        void setCodeHighlighter(GodotCodeHighlighter* p_node) {
            code_highlighter = p_node;
            setResource(code_highlighter);
        }
    };
}

#endif // CODE_HIGHLIGHTER_H