//
// Created by mintkat on 1/31/25.
//

#include "app.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

#include"core/lua_bind.h"
#include "core/scene_system.h"

using namespace newhaven;
using namespace godot;

void App::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start"), &App::start);
}

App::App() {
}

App::~App() {
    //UtilityFunctions::print("App destructor");
}

void App::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    global_state.open_libraries( sol::lib::base, sol::lib::bit32, sol::lib::coroutine,
                                     sol::lib::count, sol::lib::math, sol::lib::string,
                                     sol::lib::table, sol::lib::utf8, sol::lib::jit );

    global_state["print"] = [this]( sol::variadic_args args ) {
        String msg;
        for ( const auto &arg : args )
        {
            if ( arg.is<std::string>() )
            {
                std::string str = arg.as<std::string>();
                msg += str.c_str();
            }
        }
        godot::UtilityFunctions::print( msg );
    };

    UtilityFunctions::print("Hello, World!");

    newhaven_core::bind_base_types( global_state );
    newhaven_core::bindSceneSystem( global_state );
    //newhaven_core::bind_all_godot_classes( global_state );
    //newhaven_core::initialize_lua( global_state );

    global_state.script(R"(
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
}

void App::start() {
}