#include "syntax_highlighter.h"
#include "text_edit.h"

namespace sunaba::ui {
    TextEdit* SyntaxHighlighter::getTextEdit() {
        return new TextEdit(syntax_highlighter->get_text_edit());
    }
    
    void bindSyntaxHighlighter(sol::state &lua) {
        lua.new_usertype<SyntaxHighlighter>("SyntaxHighlighter",
            "new", sol::factories(
                []() { return new SyntaxHighlighter(); }
            ),
            sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource>(),
            "clearHighlightingCache", &SyntaxHighlighter::clearHighlightingCache,
            "getLineSyntaxHighlighting", &SyntaxHighlighter::getLineSyntaxHighlighting,
            "getTextEdit", &SyntaxHighlighter::getTextEdit,
            "updateCache", &SyntaxHighlighter::updateCache,
            "cast", [](sunaba::core::Resource* p_resource) {
                return new SyntaxHighlighter(godot::Object::cast_to<GodotSyntaxHighlighter>(p_resource->getResource()));
            }
        );
    }
}