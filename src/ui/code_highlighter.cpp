#include "code_highlighter.h"

namespace lucidfx::ui {
    void bindCodeHighlighter(sol::state &lua) {
        lua.new_usertype<CodeHighlighter>("CodeHighlighter",
            "new", sol::factories(
                []() { return new CodeHighlighter(); }
            ),
            sol::base_classes, sol::bases<lucidfx::core::BaseObject, lucidfx::core::Resource, SyntaxHighlighter>(),
            "colorRegions", sol::property(&CodeHighlighter::getColorRegions, &CodeHighlighter::setColorRegions),
            "functionColor", sol::property(&CodeHighlighter::getFunctionColor, &CodeHighlighter::setFunctionColor),
            "keywordColors", sol::property(&CodeHighlighter::getKeywordColors, &CodeHighlighter::setKeywordColors),
            "memberKeywordColors", sol::property(&CodeHighlighter::getMemberKeywordColors, &CodeHighlighter::setMemberKeywordColors),
            "memberVariableColor", sol::property(&CodeHighlighter::getMemberVariableColor, &CodeHighlighter::setMemberVariableColor),
            "numberColor", sol::property(&CodeHighlighter::getNumberColor, &CodeHighlighter::setNumberColor),
            "symbolColor", sol::property(&CodeHighlighter::getSymbolColor, &CodeHighlighter::setSymbolColor),
            "addColorRegion", &CodeHighlighter::addColorRegion,
            "addKeywordColor", &CodeHighlighter::addKeywordColor,
            "addMemberKeywordColor", &CodeHighlighter::addMemberKeywordColor,
            "clearColorRegions", &CodeHighlighter::clearColorRegions,
            "clearKeywordColors", &CodeHighlighter::clearKeywordColors,
            "clearMemberKeywordColors", &CodeHighlighter::clearMemberKeywordColors,
            "getKeywordColor", &CodeHighlighter::getKeywordColor,
            "getMemberKeywordColor", &CodeHighlighter::getMemberKeywordColor,
            "hasColorRegion", &CodeHighlighter::hasColorRegion,
            "hasKeywordColor", &CodeHighlighter::hasKeywordColor,
            "hasMemberKeywordColor", &CodeHighlighter::hasMemberKeywordColor,
            "removeColorRegion", &CodeHighlighter::removeColorRegion,
            "removeKeywordColor", &CodeHighlighter::removeKeywordColor,
            "removeMemberKeywordColor", &CodeHighlighter::removeMemberKeywordColor,
            "cast", [](lucidfx::core::Resource* p_resource) {
                return new CodeHighlighter(godot::Object::cast_to<GodotCodeHighlighter>(p_resource->getResource()));
            }
        );
    }
}