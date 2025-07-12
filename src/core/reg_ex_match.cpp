#include "reg_ex_match.h"

namespace kenai::core {
    void bindRegExMatch(sol::state& lua) {
        lua.new_usertype<RegExMatch>("RegExMatch",
            "new", sol::factories(
                []() { return new RegExMatch(); }
            ),
            sol::base_classes, sol::bases<BaseObject>(),
            "names", sol::readonly_property(&RegExMatch::getNames),
            "strings", sol::readonly_property(&RegExMatch::getStrings),
            "subject", sol::readonly_property(&RegExMatch::getSubject),
            "getEnd", &RegExMatch::getEnd,
            "getGroupCount", &RegExMatch::getGroupCount,
            "getStart", &RegExMatch::getStart,
            "getString", &RegExMatch::getString,
            "isValid", &RegExMatch::isValid,
            "isNull", &RegExMatch::isNull
        );
    }
}