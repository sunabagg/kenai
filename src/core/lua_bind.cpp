//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/basis.hpp>

#include "lua_function_wrapper.h"

using namespace godot;
using namespace lucidfx::core;

void lucidfx::core::bind_class_to_lua(sol::state& lua, const String& class_name) {
    // Get class info
    if (!ClassDB::class_exists(class_name)) {
        godot::UtilityFunctions::print("Class not found: ", class_name);
        return;
    }

    auto indexFunc = [class_name, &lua](Object *obj, const std::string key) {
        String key_string = String(key.c_str()); //String(maybe_string_key.value().c_str());
        if (key_string.begins_with("emit_")) {
            String signal_name = key_string.substr(5);
            auto emit_func = [obj, signal_name](sol::variadic_args va) {
                Array args;
                for (const auto& arg : va) {
                    args.append(arg);
                }    
                obj->emit_signal(signal_name, args);
            };
            return sol::make_object(lua, emit_func);
        }
        else if (key_string.begins_with("connect_")) {
            String signal_name = key_string.substr(7);
            auto connect_func = [obj, signal_name](sol::stack_object func) {
                auto function = func.as<sol::function>();
                Callable callable = lucidfx::core::create_callable_from_lua_function(function);
                obj->connect(signal_name, callable);
                return callable;
            };
            return sol::make_object(lua, connect_func);
        }
        else if (key_string.begins_with("disconnect_")) {
            String signal_name = key_string.substr(10);
            auto disconnect_func = [obj, signal_name](sol::stack_object func) {
                Callable callable = func.as<Callable>();
                obj->disconnect(signal_name, callable);
            };
            return sol::make_object(lua, disconnect_func);
        }
        
        if (ClassDB::class_has_integer_constant(class_name, key_string)) {
            return sol::make_object(lua, ClassDB::class_get_integer_constant(class_name, key_string));
        }

        if (ClassDB::class_has_method(class_name, key_string)) {
            auto func = [obj, key_string](sol::variadic_args va) {
                Array args;
                for (const auto& arg : va) {
                    args.append(arg);
                }
                return obj->callv(key_string, args);
            };

            return sol::make_object(lua, func);
        }
        
        auto value = obj->get(key_string);
        if (value.get_type() != Variant::NIL) {
            return sol::make_object(lua, value);
        }

        return sol::make_object(lua, sol::lua_nil_t());
    };

    auto new_indexFunc = [class_name](Object *obj, sol::stack_object key, sol::stack_object value, sol::this_state L) {
        auto maybe_string_key
            = key.as<sol::optional<std::string>>();
        if (maybe_string_key) {
            String key_string = String(maybe_string_key.value().c_str());
            auto old_value = obj->get(key_string);
            if (old_value.get_type() != Variant::NIL) {
                Variant new_value;
                if (value.is<std::string>()) {
                    String str = String(value.as<std::string>().c_str());
                    new_value = str;
                }
                else if (value.is<int>()) {
                    new_value = int(value.as<int>());
                }
                else if (value.is<float>()) {
                    new_value = float(value.as<float>());
                }
                else if (value.is<bool>()) {
                    new_value = bool(value.as<bool>());
                }
                else if (value.is<double>()) {
                    new_value = double(value.as<double>());
                }
                else if (value.is<godot::Object*>()) {
                    new_value = value.as<godot::Object*>();
                }
                obj->set(key_string, new_value);
                return sol::make_object(L, new_value);
            }
        }
    };
    // Create a new Lua usertype
    sol::usertype<godot::Object> ut; ut = lua.new_usertype<godot::Object>(
        class_name.utf8().get_data(),
        sol::factories([class_name, &lua, ut, indexFunc, new_indexFunc]() { 
            auto obj = ClassDB::instantiate( class_name ); 
            RefCounted *ref_obj = Object::cast_to<RefCounted>(obj);
            if (ref_obj) {
                ref_obj->reference();
            }
            return obj;
        }),
        sol::meta_function::index, sol::factories(indexFunc),
        sol::meta_function::new_index, sol::factories(new_indexFunc)
    );
    /*
    PackedStringArray enum_list = ClassDB::class_get_enum_list(class_name);
    for (const auto& enum_name : enum_list) {
        PackedStringArray enum_constants = ClassDB::class_get_enum_constants(class_name, enum_name);
        UtilityFunctions::print(enum_constants);
        for (const String enum_constant : enum_constants) {
            int enum_value = ClassDB::class_get_integer_constant(class_name, enum_constant);
            UtilityFunctions::print("Binding enum constant: ", enum_constant, " with value: ", enum_value);
            auto get_func = [enum_value]( godot::Object *obj ) { return enum_value; };
            auto set_func = []( godot::Object *obj, const Variant &value ) {};
            ut.set( enum_constant.utf8().get_data(), sol::property( get_func, set_func ) );
        }
        //sol::table enum_table = lua.create_table();
        //for (const auto& enum_value : enum_constants) {
            //enum_table[enum_value] = enum_value;
        //}
        //ut[enum_name.utf8().get_data()] = enum_table;
    }

    TypedArray<Dictionary> property_list = ClassDB::class_get_property_list(class_name);
    TypedArray<Dictionary>* property_list_ptr = &property_list;
    
    // Get property list
    for (int i = 0; i < property_list_ptr->size(); i++) {
        Dictionary property = property_list[i];
        String property_name = property["name"];
        godot::UtilityFunctions::print("Binding property: ", property_name);
        auto get_func = [property_name]( godot::Object *obj ) { return obj->get( property_name ); };
        auto set_func = [property_name]( godot::Object *obj, const Variant &value ) {
            obj->set( property_name, value );
        };
        ut.set( property_name.utf8().get_data(), sol::property( get_func, set_func ) );
    }

    // Get method list
    TypedArray<Dictionary> method_list = ClassDB::class_get_method_list(class_name);
    TypedArray<Dictionary>* method_list_ptr = &method_list;
    for (int i = 0; i < method_list_ptr->size(); i++)
    {   
        Dictionary method = method_list[i];
        //godot::UtilityFunctions::print(JSON::stringify(method));

        String method_name = method["name"];
        godot::UtilityFunctions::print("Binding method: ", method_name);
        auto func = [class_name, method](godot::Object* obj, sol::variadic_args va) {
                Array args;
                for (const auto& arg : va) {
                    args.append(arg);
                }
                return obj->callv(method["name"], args);
        };

        //sol::function lua_func = sol::function::;

        ut.set(method_name.utf8().get_data(), func);
        /*if (!(ut.get)) {
            godot::UtilityFunctions::print("Failed to bind method: ", method_name);
        }
    }
    
    TypedArray<Dictionary> signal_list = ClassDB::class_get_signal_list(class_name);
    TypedArray<Dictionary>* signal_list_ptr = &signal_list;

    for (int i = 0; i < signal_list_ptr->size(); i++)
    {
        Dictionary signal = signal_list[i];
        String signal_name = signal["name"];
        godot::UtilityFunctions::print("Binding signal: ", signal_name);

        auto emit_func = [class_name, signal](godot::Object* obj, sol::variadic_args va) {
            Array args;
            for (const auto& arg : va) {
                args.append(arg);
            }    
            obj->emit_signal(signal["name"], args);
        };

        ut.set(("emit_" + signal_name).utf8().get_data(), emit_func);

        auto connect_func = [class_name, signal](godot::Object* obj, sol::variadic_args va) {
            auto function = va[0].as<sol::function>();
            Callable callable = lucidfx::core::create_callable_from_lua_function(function);
            obj->connect(signal["name"], callable);
            //lucidfx::core::SignalDB::add_signal(obj, signal["name"], callable);
            return callable;
        };

        ut.set(("connect_" + signal_name).utf8().get_data(), connect_func);

        auto disconnect_func = [class_name, signal](godot::Object* obj, sol::variadic_args va) {
            Callable callable = va[0].as<Callable>();
            obj->disconnect(signal["name"], callable);
            //lucidfx::core::SignalDB::remove_signal(obj, signal["name"]);
        };

        ut.set(("disconnect_" + signal_name).utf8().get_data(), disconnect_func);
    }*/
}

void lucidfx::core::bind_all_godot_classes(sol::state& lua) {
    auto all_classes = ClassDB::get_class_list();

    for (const String& class_name : all_classes) {
        godot::UtilityFunctions::print("binding class: ", class_name);
        if (class_name == String("OS") || class_name == String("DisplayServer") ||
            class_name == String("RenderingDevice") || class_name == String("FileAccess")
            || class_name == String("Engine") || class_name == String("SceneTree")){
            continue; // Exclude core engine classes
        }
        bind_class_to_lua(lua, class_name);
    }
}

void lucidfx::core::initialize_lua(sol::state& lua) {
    bind_all_godot_classes(lua);

    lua.script(R"(
        myNode = Node.new()
        if myNode == nil then
            print("Node is nil")
        else
            print("Node is not nil")
        end
        --local str = myNode.toString()
        --print(str)  -- Example usage
    )");

    lua.script(R"(
        function printAllGlobals()
	        local seen={}
	        local function dump(t,i)
				if t == nil then
                    --print("t is nil)
					return
				end
		        seen[t]=true
		        local s={}
		        local n=0
		        for k, v in pairs(t) do
			        n=n+1
                    if s[n] == nil then
                        s[n] = ""
                    end
			        s[n]=tostring(k)
		        end
		        table.sort(s)
		        for k,v in ipairs(s) do
			        print(i .. v)
			        v=t[v]
			        if type(v)=="table" and not seen[v] then
				        dump(v,i.."\t")
                    elseif type(v)=="userdata" and not seen[v] then
                        dump(getmetatable(v),i.."\t")
			        end
		        end
	        end

	        dump(_G,"")
        end

        if _G == nil then
            print("Global table is nil")
        else
            print("Global table is not nil")
        end

        printAllGlobals()
    )");

    lua.script(R"(
        print("Hello from Lua!")
    )");

    lua.script(R"(
        if myNode == nil then
            print("Node is nil")
        else
            print("Node is not nil")
            print(myNode.__type.name)
            if myNode.__index == nil then
                print("Node.__index is nil")
            else
                print("Node.__index is not nil")
            end
            if myNode['name'] ~= nil then
                local name = myNode['name']
                print(name)  -- Example usage
            else
                print("Node does not have a name field")
            end
        end
    )");
}