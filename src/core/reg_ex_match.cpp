#include "reg_ex_match.h"

namespace sunaba::core {
    void bindRegExMatch(sol::state& lua) {
        lua.new_usertype<RegExMatch>("RegExMatch",
            sol::constructors<RegExMatch(), RegExMatch(GodotRegExMatch*)>(),
            "getNames", &RegExMatch::getNames,
            "getStrings", &RegExMatch::getStrings,
            "getSubject", &RegExMatch::getSubject,
            "getEnd", &RegExMatch::getEnd,
            "getGroupCount", &RegExMatch::getGroupCount,
            "getStart", &RegExMatch::getStart,
            "getString", &RegExMatch::getString
        );
    }
}