#include "code_highlighter.h"

namespace sunaba::ui {
    void bindCodeHighlighter(sol::state &lua) {
        lua.new_usertype<CodeHighlighter>("CodeHighlighter",
            sol::constructors<CodeHighlighter()>(),
            sol::base_classes, sol::bases<sunaba::core::BaseObject, sunaba::core::Resource, SyntaxHighlighter>(),
            "colorRegions", sol::property(&CodeHighlighter::getColorRegions, &CodeHighlighter::setColorRegions),
            "functionColor", sol::property(&CodeHighlighter::getFunctionColor, &CodeHighlighter::setFunctionColor),
            "keywordColors", sol::property(&CodeHighlighter::getKeywordColors, &CodeHighlighter::setKeywordColors),
            "memberKeywordColors", sol::property(&CodeHighlighter::getMemberKeywordColors, &CodeHighlighter::setMemberKeywordColors),
        );
    }
}