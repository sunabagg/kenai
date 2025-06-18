#ifndef REG_EX_H
#define REG_EX_H

#include <godot_cpp/classes/reg_ex.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotRegEx godot::RegEx

#include "base_object.h"
#include "reg_ex_match.h"

using namespace godot;

namespace sunaba::core {
    void bindRegEx(sol::state& lua);

    class RegEx: public BaseObject {
        private:
            godot::Ref<GodotRegEx> reg_ex = nullptr; // Pointer to the RegEx instance
        public:
            RegEx(GodotRegEx* regex) {
                setRegEx(regex);
            }

            RegEx() {
                setRegEx(godot::Ref<GodotRegEx>(memnew(GodotRegEx)));
            }

            godot::Ref<GodotRegEx> getRegEx() const {
                return reg_ex;
            }

            void setRegEx(godot::Ref<GodotRegEx> regex) {
                reg_ex = regex;
                reg_ex->reference();
            }

            void clear() {
                reg_ex->clear();
            }
    };
}

#endif // REG_EX_H