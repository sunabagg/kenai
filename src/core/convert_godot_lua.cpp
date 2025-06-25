#include "convert_godot_lua.h"

using namespace godot;

namespace lucidware::core {
    template<typename ref_t>
    Variant to_variant(const sol::basic_object<ref_t>& object) {
        if (object.template is<bool>()) {
            return object.template as<bool>();
        }
        else if (object.template is<std::string>()) {
            return String(object.template as<std::string>().c_str());
        }
        else if (object.template is<int64_t>()) {
            return object.template as<int64_t>();
        }
        else if (object.template is<double>()) {
            return object.template as<double>();
        }
        else {
            return Variant();
        }
    }
    
    Variant to_variant(const sol::object& object) {
        return to_variant<>(object);
    }
    
    Variant to_variant(const sol::stack_object& object) {
        return to_variant<>(object);
    }
    
    Variant to_variant(const sol::stack_proxy_base& proxy) {
        return to_variant<>(sol::stack_object(proxy.lua_state(), proxy.stack_index()));
    }
    
    
    
    Variant to_variant(lua_State *L, int index) {
        return to_variant(sol::stack_object(L, index));
    }
    
    sol::stack_object to_lua(lua_State *lua_state, const Variant& value) {
        switch (value.get_type()) {
            case Variant::NIL:
                sol::stack::push(lua_state, sol::lua_nil);
                break;
    
            case Variant::BOOL:
                sol::stack::push(lua_state, (bool) value);
                break;
    
            case Variant::INT:
                sol::stack::push(lua_state, (int64_t) value);
                break;
    
            case Variant::FLOAT:
                sol::stack::push(lua_state, (double) value);
                break;
    
            case Variant::STRING:
                sol::stack::push(lua_state, String(value).utf8().get_data());
                break;
    
            case Variant::STRING_NAME:
                sol::stack::push(lua_state, std::string(String(StringName(value)).utf8().get_data()));
                break;
            
            default:
                sol::stack::push(lua_state, value);
                break;
        }
        return sol::stack_object(lua_state, -1);
    }

    Array to_array(const sol::variadic_args& args) {
        Array array;
        for (const auto& arg : args) {
            array.append(to_variant(arg));
        }
        return array;
    }

    Array to_array(const sol::table& table) {
        Array array;
        for (const auto& pair : table) {
            array.append(to_variant(pair.second));
        }
        return array;
    }

    Dictionary to_dictionary(const sol::table& table) {
        Dictionary dictionary;
        for (const auto& pair : table) {
            dictionary[to_variant(pair.first)] = to_variant(pair.second);
        }
        return dictionary;
    }

    sol::table to_table(sol::state_view& state, const Dictionary& dictionary) {
        sol::table table = state.create_table();
        for (int i = 0; i < dictionary.size(); ++i) {
            const Variant& key = dictionary.keys()[i];
            const Variant& value = dictionary[key];
            table[to_lua(state, key)] = to_lua(state, value);
        }
        return table;
    }

    sol::table to_table(sol::state_view& state, const Array& array) {
        sol::table table = state.create_table();
        for (int i = 0; i < array.size(); ++i) {
            const Variant& value = array[i];
            table[i] = to_lua(state, value);
        }
        return table;
    }
}