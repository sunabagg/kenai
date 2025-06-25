#ifndef REG_EX_H
#define REG_EX_H

#include <godot_cpp/classes/reg_ex.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotRegEx godot::RegEx

#include "base_object.h"
#include "reg_ex_match.h"

using namespace godot;

namespace lucidware::core {
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

            int compile(const std::string& pattern, bool show_error = true) {
                return reg_ex->compile(String(pattern.c_str()), show_error);
            }

            static RegEx createFromString(const std::string& pattern, bool show_error = true) {
                return RegEx(GodotRegEx::create_from_string(String(pattern.c_str()), show_error).ptr());
            }

            int getGroupCount() const {
                return reg_ex->get_group_count();
            }

            std::vector<std::string> getNames() const {
                PackedStringArray names = reg_ex->get_names();
                std::vector<std::string> result;
                result.reserve(names.size());
                for (const String& name : names) {
                    result.push_back(name.utf8().get_data());
                }
                return result;
            }

            std::string getPattern() const {
                return reg_ex->get_pattern().utf8().get_data();
            }

            bool isValid() const {
                return reg_ex->is_valid();
            }

            RegExMatch search(const std::string& subject, int offset = 0, int end = -1) const {
                return RegExMatch(reg_ex->search(String(subject.c_str()), offset, end).ptr());
            }

            std::vector<RegExMatch> searchAll(const std::string& subject, int offset = 0, int end = -1) const {
                TypedArray<GodotRegExMatch> matches = reg_ex->search_all(String(subject.c_str()), offset, end);
                std::vector<RegExMatch> result;
                result.reserve(matches.size());
                for (int i = 0; i < matches.size(); ++i) {
                    GodotRegExMatch* matchObj = Object::cast_to<GodotRegExMatch>(matches[i].operator Object*());
                    result.push_back(RegExMatch(matchObj));
                }
                return result;
            }

            std::string sub(const std::string& subject, const std::string& replacement, bool all = false, int offset = 0, int end = -1) const {
                return reg_ex->sub(String(subject.c_str()), String(replacement.c_str()), all, offset, end).utf8().get_data();
            }
    };
}

#endif // REG_EX_H