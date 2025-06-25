#include "lua_bind.h"

void lucidware::core::bind_dictionary(sol::state& lua) {
    lua.new_usertype<Dictionary>("Dictionary",
        sol::constructors<Dictionary()>(),
        "assign", &Dictionary::assign,
        "clear", &Dictionary::clear,
        "duplicate", &Dictionary::duplicate,
        "erase", &Dictionary::erase,
        "findKey", &Dictionary::find_key,
        "get", &Dictionary::get,
        "getOrAdd", &Dictionary::get_or_add,
        "has", &Dictionary::has,
        "hasAll", &Dictionary::has_all,
        "hash", &Dictionary::hash,
        "isEmpty", &Dictionary::is_empty,
        "isReadOnly", &Dictionary::is_read_only,
        "keys", &Dictionary::keys,
        "makeReadOnly", &Dictionary::make_read_only,
        "merge", &Dictionary::merge,
        "merged", &Dictionary::merged,
        "recursiveEqual", &Dictionary::recursive_equal,
        "set", &Dictionary::set,
        "size", &Dictionary::size,
        "sort", &Dictionary::sort,
        "values", &Dictionary::values,
        "__pairs", [](Dictionary& dict) {
            return sol::as_function([&dict, i = 0](sol::this_state s) mutable -> std::tuple<sol::object, sol::object> {
            if (i < dict.size()) {
                return { sol::make_object(s, dict.keys()[i]), sol::make_object(s, dict.values()[i++]) };
            } else {
                return { sol::lua_nil, sol::lua_nil };
            }
            });
        },
        "__ipairs", [](Dictionary& dict) {
            return sol::as_function([](sol::this_state s, Dictionary& d, int i) -> std::tuple<sol::object, sol::object> {
                i++;
                if (i <= d.size()) {
                    return { sol::make_object(s, d.keys()[i - 1]), sol::make_object(s, d.values()[i - 1]) };
                }
                return { sol::lua_nil, sol::lua_nil };
            });
        },
        sol::meta_function::index, [](Dictionary& dict, const Variant& key) { return dict[key]; },
        sol::meta_function::new_index, [](Dictionary& dict, const Variant& key, const Variant& value) {
            dict.set(key, value);
        },
        sol::meta_function::length, &Dictionary::size,
        sol::meta_function::to_string, [](const Dictionary& dict) {
            return "<Dictionary size=" + std::to_string(dict.size()) + ">";
        }
    );
}