//
// Created by lucas on 2/1/2025.
//

#ifndef LUA_FUNCTION_WRAPPER_H
#define LUA_FUNCTION_WRAPPER_H

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <sol/sol.hpp>
#include <map>

using namespace godot;

namespace lucidfx::core {
    class LuaFunctionWrapper : public Object {
        GDCLASS(LuaFunctionWrapper, Object);
    private:
        sol::function lua_function;
    public:
        void set_lua_function(sol::function func) {
            lua_function = func;
        }
        void invoke_lua_function() {
            lua_function();
        }
        static void _bind_methods() {
            ClassDB::bind_method(D_METHOD("invoke_lua_function"), &LuaFunctionWrapper::invoke_lua_function);
        }
    };

    Callable create_callable_from_lua_function(sol::function func) {
        LuaFunctionWrapper* wrapper = memnew(LuaFunctionWrapper);
        wrapper->set_lua_function(func);
        Callable callable(wrapper, "invoke_lua_function");
        return callable;
    }
/*
    class LuaSignalKey : public Object {
    public:
        Object* obj;
        String signal_name;    
    };

    class SignalDB {
        private:
            static std::map<LuaSignalKey, Callable> signal_map;
        public:
            static void add_signal(Object* obj, String signal_name, Callable callable) {
                LuaSignalKey key;
                key.obj = obj;
                key.signal_name = signal_name;
                signal_map[key] = callable;
            }

            static Callable get_signal(Object* obj, String signal_name) {
                LuaSignalKey key;
                key.obj = obj;
                key.signal_name = signal_name;
                return signal_map[key];
            }

            static void remove_signal(Object* obj, String signal_name) {
                LuaSignalKey key;
                key.obj = obj;
                key.signal_name = signal_name;
                signal_map.erase(key);
            }
    };
*/
}

#endif //LUA_FUNCTION_WRAPPER_H
