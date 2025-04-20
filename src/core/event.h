#ifndef EVENT_H
#define EVENT_H

#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>
#include <vector>

#include "base_object.h"

namespace sunaba::core {

    class Event : public BaseObject {
        private:
            std::vector<std::function<void(godot::Array)>*> listeners;
            std::vector<sol::function> lua_listeners;

            void callCppListener(void* listener, godot::Array args) {
                // Call the C++ listener function with the provided arguments
                // Assuming listener is a function pointer or a callable object
                auto func = static_cast<void(*)(godot::Array)>(listener);
                func(args);
            }

            void callLuaListener(sol::function listener, sol::variadic_args args) {
                // Call the Lua listener function with the provided arguments
                listener(args);
            }

            public:
            Event() = default;
            ~Event() {
                for (auto listener : listeners) {
                    delete listener; // Assuming listeners are dynamically allocated
                }
            }

            void connect(std::function<void(godot::Array)>* listener) {
                listeners.push_back(listener);
            }

            void connectLua(sol::function listener) {
                lua_listeners.push_back(listener);
            }

            void disconnect(std::function<void(godot::Array)>* listener) {
                auto it = std::remove(listeners.begin(), listeners.end(), listener);
                if (it != listeners.end()) {
                    listeners.erase(it, listeners.end());
                }
            }

            void disconnectLua(sol::function listener) {
                auto it = std::remove(lua_listeners.begin(), lua_listeners.end(), listener);
                if (it != lua_listeners.end()) {
                    lua_listeners.erase(it, lua_listeners.end());
                }
            }

            template<typename... Args>
            void emit(Args... args) {
                for (auto listener : listeners) {
                    callCppListener(listener, args...);
                }
                for (auto lua_listener : lua_listeners) {
                    sol::variadic_args vargs = sol::variadic_args(args...);
                    callLuaListener(lua_listener, vargs);
                }
            }

            void emitLua(sol::variadic_args args) {
                for (auto listemer: listeners) {
                    godot::Array args_array;
                    for (auto arg : args) {
                        args_array.append(arg.as<godot::Variant>());
                    }
                    callCppListener(listemer, args_array);
                }
                for (auto lua_listener : lua_listeners) {
                    callLuaListener(lua_listener, args);
                }
            }

            void emitGodot(godot::Array args) {
                for (auto listemer: listeners) {
                    callCppListener(listemer, args);
                }

                for (auto lua_listener : lua_listeners) {
                    callLuaListener(lua_listener, args);
                }
            }


    };
}

#endif // EVENT_H
