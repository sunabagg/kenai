//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>

using namespace godot;
using namespace newhaven_core;

void newhaven_core::bind_class_to_lua(sol::state& lua, const String& class_name) {
    // Get class info
    if (!ClassDB::class_exists(class_name)) {
        godot::UtilityFunctions::print("Class not found: ", class_name);
        return;
    }
    // Create a new Lua usertype
    sol::usertype<godot::Object> ut = lua.new_usertype<godot::Object>(
        class_name.utf8().get_data(),
        sol::constructors<>(),
        "new", sol::factories([class_name]() { 
            return ClassDB::instantiate( class_name ); 
            }
        )
    );

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
        }*/
    }
    

    // Iterate through methods and bind them
    /*for (const auto& method : method_list) {
        godot::UtilityFunctions::print("Binding method: ", method.name);
        auto func = [class_name, method](godot::Object* obj, sol::variadic_args va) {
                Array args;
                for (const auto& arg : va) {
                    args.append(arg);
                }
                return obj->call(method.name, args);
        };
        lua[class_name.utf8().get_data()][((String)method.name).utf8().get_data()] = func;

        if (!(lua[class_name.utf8().get_data()][((String)method.name).utf8().get_data()] == func)) {
            godot::UtilityFunctions::print("Failed to bind method: ", method.name);
        }
    }*/
}

void newhaven_core::bind_all_godot_classes(sol::state& lua) {
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

void newhaven_core::initialize_lua(sol::state& lua) {
    bind_all_godot_classes(lua);

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

    /*lua.script(R"(
        local node = Node.new()
        print(node:get_name())  -- Example usage
    )");*/
}