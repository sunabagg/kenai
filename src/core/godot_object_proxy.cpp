#include "godot_object_proxy.h"
#include "lua_function_wrapper.h"

using namespace godot;
using namespace lucidfx::core;


sol::object GodotObjectProxy::get(sol::stack_object key, sol::this_state L) {
    auto maybe_string_key
		     = key.as<sol::optional<std::string>>();
    if (maybe_string_key) {
        String key_string = String(maybe_string_key.value().c_str());
        if (key_string.begins_with("emit_")) {
            String signal_name = key_string.substr(5);
            auto emit_func = [this, signal_name](sol::variadic_args va) {
                Array args;
                for (const auto& arg : va) {
                    args.append(arg);
                }    
                this->object->emit_signal(signal_name, args);
            };
        }
        
        if (ClassDB::class_has_integer_constant(className, key_string)) {
            return sol::make_object(L, ClassDB::class_get_integer_constant(className, key_string));
        }

        if (ClassDB::class_has_method(className, key_string)) {
            auto func = [this, key_string](sol::variadic_args va) {
                Array args;
                for (const auto& arg : va) {
                    args.append(arg);
                }
                return this->object->callv(key_string, args);
            };

             return sol::make_object(L, func);
        }
        
        auto value = object->get(key_string);
        if (value.get_type() != Variant::NIL) {
            return sol::make_object(L, value);
        }

        return sol::lua_nil;
    }
}