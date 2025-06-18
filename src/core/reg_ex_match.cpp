#include "reg_ex_match.h"

namespace sunaba::core {
    void bindRegExMatch(sol::state& lua) {
        lua.new_usertype<RegExMatch>("RegExMatch",
            sol::constructors<RegExMatch(), RegExMatch(GodotRegExMatch*)>(),
            "names", sol::readonly_property(&RegExMatch::getNames),
            "strings", sol::readonly_property(&RegExMatch::getStrings),
            "getSubject", &RegExMatch::getSubject,
            "getEnd", &RegExMatch::getEnd,
            "getGroupCount", &RegExMatch::getGroupCount,
            "getStart", &RegExMatch::getStart,
            "getString", &RegExMatch::getString
        );
    }
}