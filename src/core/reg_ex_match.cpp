#include "reg_ex_match.h"

namespace sunaba::core {
    void bindRegExMatch(sol::state& lua) {
        lua.new_usertype<RegExMatch>("RegExMatch",
            sol::constructors<RegExMatch()>(),
            "names", sol::readonly_property(&RegExMatch::getNames),
            "strings", sol::readonly_property(&RegExMatch::getStrings),
            "subject", sol::readonly_property(&RegExMatch::getSubject),
            "getEnd", &RegExMatch::getEnd,
            "getGroupCount", &RegExMatch::getGroupCount,
            "getStart", &RegExMatch::getStart,
            "getString", &RegExMatch::getString,
            "isNull", &RegExMatch::isNull
        );
    }
}