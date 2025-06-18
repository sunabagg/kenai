#ifndef REG_EX_MATCH_H
#define REG_EX_MATCH_H

#include <godot_cpp/classes/reg_ex_match.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotRegExMatch godot::RegExMatch

#include "../core/base_object.h"

using namespace godot;

namespace sunaba::core {
    void bindRegExMatch(sol::state& lua);

    class RegExMatch : public BaseObject {
        private:
            godot::Ref<GodotRegExMatch> reg_ex_match = nullptr; // Pointer to the RegExMatch instance
        public:
            // Constructor with GodotRegExMatch parameter
            RegExMatch(GodotRegExMatch* match) {
                setRegExMatch(match);
            }

            // Constructor with no parameters
            RegExMatch() {
                setRegExMatch(godot::Ref<GodotRegExMatch>(memnew(GodotRegExMatch)));
            }

            // Getter for the RegExMatch node
            godot::Ref<GodotRegExMatch> getRegExMatch() const {
                return reg_ex_match;
            }

            // Setter for the RegExMatch node
            void setRegExMatch(godot::Ref<GodotRegExMatch> match) {
                reg_ex_match = match;
                reg_ex_match->reference();
            }

            Dictionary getNames() const {
                return reg_ex_match->get_names();
            }

            std::vector<std::string> getStrings() const {
                PackedStringArray strings = reg_ex_match->get_strings();
                std::vector<std::string> result;
                result.reserve(strings.size());
                for (const String& str : strings) {
                    result.push_back(str.utf8().get_data());
                }
                return result;
            }

            std::string getSubject() const {
                return reg_ex_match->get_subject().utf8().get_data();
            }

            int getEnd(const Variant& name = 0) const {
                return reg_ex_match->get_end(name);
            }

            int getGroupCount() const {
                return reg_ex_match->get_group_count();
            }

            int getStart(const Variant& name = 0) const {
                return reg_ex_match->get_start(name);
            }

            std::string getString(const Variant& name = 0) const {
                return reg_ex_match->get_string(name).utf8().get_data();
            }
    };
}

#endif