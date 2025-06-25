#include "reg_ex.h"

namespace lucidfx::core {
    void bindRegEx(sol::state& lua) {
        lua.new_usertype<RegEx>("RegEx",
            "new", sol::factories(
                []() { return new RegEx(); }
            ),
            sol::base_classes, sol::bases<BaseObject>(),
            "reg_ex", sol::readonly_property(&RegEx::getRegEx),
            "clear", &RegEx::clear,
            "compile", &RegEx::compile,
            "createFromString", &RegEx::createFromString,
            "getGroupCount", &RegEx::getGroupCount,
            "getNames", &RegEx::getNames,
            "getPattern", &RegEx::getPattern,
            "isValid", &RegEx::isValid,
            "search", &RegEx::search,
            "searchAll", &RegEx::searchAll,
            "sub", &RegEx::sub
        );
    }
}