#include "code_highlighter.h"

namespace sunaba::ui {
    void bindCodeHighlighter(sol::state &lua) {
        lua.new_usertype<CodeHighlighter>("CodeHighlighter",
            sol::constructors<CodeHighlighter()>(),
            sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, SyntaxHighlighter>()
        );
    }
}