#ifndef EVENT_H
#define EVENT_H

#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/godot.hpp>
#include <sol/sol.hpp>
#include <vector>

#include "base_object.h"

using namespace godot;

namespace lucidware::core {
    void bindEvent(sol::state &lua);

    class TableMethodNamePair {
        public:
            sol::table table;
            std::string method_name;

            TableMethodNamePair(sol::table t, const std::string& name) : table(t), method_name(name) {}
    };

    class Event : public BaseObject {
        private:
            std::vector<std::function<void(godot::Array)>> listeners = {};
            std::vector<sol::function> lua_listeners = {};    
            std::vector<TableMethodNamePair> lua_table_listeners = {};       
            
            void callLuaListener(sol::function listener, sol::table args) {
                // Call the Lua listener function with the provided arguments
                listener(sol::as_args(args));
            }

            bool hasLuaListeners = false;

            public:
            Event() {

            }

            ~Event() {
                clear();
            }
            
            void connect(std::function<void(godot::Array)> listener) {
                listeners.push_back(listener);
            }            
            
            void connectLua(sol::function listener) {
                lua_listeners.push_back(listener);
                if (lua_listeners.size() > 0) // Check if there are any Lua listeners
                    hasLuaListeners = true;
                else
                    hasLuaListeners = false;
            }

            void connectLuaTable(lua_State* L, sol::table table, const std::string& method_name) {
                // Check if the table already has a listener for this method
                for (const auto& pair : lua_table_listeners) {
                    if (pair.table == table && pair.method_name == method_name) {
                        return; // Already connected
                    }
                }
                lua_table_listeners.emplace_back(table, method_name);
            }

            void disconnectLuaTable(lua_State* L, sol::table table, const std::string& method_name) {
                auto it = std::remove_if(lua_table_listeners.begin(), lua_table_listeners.end(),
                    [&table, &method_name](const TableMethodNamePair& pair) {
                        return pair.table == table && pair.method_name == method_name;
                    });
                lua_table_listeners.erase(it, lua_table_listeners.end());
            }

            void disconnect(std::function<void(godot::Array)> listener) {
                listeners.erase(
                    std::remove_if(listeners.begin(), listeners.end(),
                        [&listener](const std::function<void(godot::Array)>& existing_listener) {
                            // Compare the target of the function pointers
                            return listener.target_type() == existing_listener.target_type() &&
                                   listener.target<void(godot::Array)>() == existing_listener.target<void(godot::Array)>();
                        }),
                    listeners.end());
            }            void disconnectLua(sol::function listener) {
                auto it = std::remove(lua_listeners.begin(), lua_listeners.end(), listener);
                if (it != lua_listeners.end()) {
                    lua_listeners.erase(it, lua_listeners.end());
                }
            }

            void emitLua(sol::variadic_args args) {
                /*for (auto listemer: listeners) {
                    godot::Array args_array;
                    for (auto arg : args) {
                        args_array.append(arg.as<godot::Variant>());
                    }
                    listemer(args_array);
                }*/                
               for (size_t i = 0; i < lua_listeners.size(); ++i) {
                    sol::function lua_listener = lua_listeners[i];
                    sol::state_view lua_state = sol::state_view(lua_listener.lua_state());
                    sol::table lua_args = lua_state.create_table(args.size(), 0);
                    for (int j = 0; j < args.size(); ++j) {
                        lua_args[j + 1] = args[j]; // Lua tables are 1-indexed
                    }
                    callLuaListener(lua_listener, lua_args);
                }
            }

            void emit(godot::Array args) {
                /*for (auto& listener : listeners) {
                    listener(args);
                }*/

                /*for (sol::function lua_listener : lua_listeners) {
                    sol::state_view lua_state = sol::state_view(lua_listener.lua_state());
                    sol::table lua_args = lua_state.create_table(args.size(), 0);
                    for (int i = 0; i < args.size(); ++i) {
                        lua_args[i + 1] = args[i]; // Lua tables are 1-indexed
                    }
                    callLuaListener(lua_listener, lua_args);
                }*/

                // Here comes yet another fucking hack.
                if (hasLuaListeners == true) {
                    if (lua_listeners.size() > 0) { // Check if there are any Lua listeners
                        for (size_t i = 0; i < lua_listeners.size(); i++) {
                            sol::function lua_listener = lua_listeners[i];
                            if (!lua_listener.valid()) {
                                continue; // Skip invalid listeners
                            }
                            sol::state_view lua_state = sol::state_view(lua_listener.lua_state());
                            if (!lua_state || lua_state.lua_state() == nullptr) {
                                continue; // Skip if the Lua state is invalid
                            }
                            sol::table lua_args = lua_state.create_table(args.size(), 0);
                            for (int j = 0; j < args.size(); ++j) {
                                lua_args[j + 1] = args[j]; // Lua tables are 1-indexed
                            }
                            callLuaListener(lua_listener, lua_args);
                        }
                    }
                }

                /*
                if (lua_table_listeners != std::vector<TableMethodNamePair>())  // Check if there are any Lua table listeners
                {
                    for (const TableMethodNamePair& pair : lua_table_listeners) {
                        sol::state_view lua_state = sol::state_view(pair.table.lua_state());
                        sol::function method = pair.table[pair.method_name];
                        if (method.valid()) {
                            sol::table lua_args = lua_state.create_table(args.size(), 0);
                            for (int j = 0; j < args.size(); ++j) {
                                lua_args[j + 1] = args[j]; // Lua tables are 1-indexed
                            }
                            callLuaListener(method, lua_args);
                        }
                    }
                }*/
                
                
            }

            void clear() {
                listeners.clear();
                lua_listeners.clear();
            }
    };
}

#endif // EVENT_H
