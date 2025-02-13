//
// Created by mintkat on 1/31/25.
//

#include "app.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

#include"core/lua_bind.h"
#include "core/scene_system.h"
#include "core/scene_node.h"
#include "spatial/transform.h"
#include "spatial/camera.h"
#include "spatial/mesh/mesh_renderer.h"
#include "spatial/mesh/box.h"
#include "spatial/mesh/sphere.h"
#include "spatial/mesh/capsule.h"

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
            else if (arg.is<sol::table>())
            {
                msg += "table";
            }
            else if (arg.is<Vector3>())
            {
                Vector3 vec = arg.as<Vector3>();
                msg += String(vec);
            }
            else if (arg.is<Vector2>())
            {
                Vector2 vec = arg.as<Vector2>();
                msg += String(vec);
            }
            else if (arg.is<float>())
            {
                float f = arg.as<float>();
                Variant v = f;
                msg += v;
            }
            else if (arg.is<bool>())
            {
                bool b = arg.as<bool>();
                Variant v = b;
                msg += v;
            }
            else if (arg.is<int>())
            {
                int i = arg.as<int>();
                Variant v = i;
                msg += v;
            }
            else if (arg.is<Vector4>())
            {
                Vector4 vec = arg.as<Vector4>();
                msg += String(vec);
            }
            else if (arg.is<Vector4i>())
            {
                Vector4i vec = arg.as<Vector4i>();
                msg += String(vec);
            }
            else if (arg.is<Vector2i>())
            {
                Vector2i vec = arg.as<Vector2i>();
                msg += String(vec);
            }
            else if (arg.is<Vector3i>())
            {
                Vector3i vec = arg.as<Vector3i>();
                msg += String(vec);
            }
        }
        godot::UtilityFunctions::print( msg );
    };

    UtilityFunctions::print("Hello, World!");

    newhaven_core::bind_base_types( global_state );
    newhaven_core::bindSceneSystem( global_state );
    newhaven_spatial::bindSpatialTransform( global_state );
    newhaven_spatial::bindCamera( global_state );
    newhaven_spatial_mesh::bindMeshRenderer( global_state );
    newhaven_spatial_mesh::bindBox( global_state );
    newhaven_spatial_mesh::bindSphere( global_state );
    newhaven_spatial_mesh::bindCapsule( global_state );

    //newhaven_core::bind_all_godot_classes( global_state );
    //newhaven_core::initialize_lua( global_state );

    global_state.set_function( "createScene", [this]() {
        return createScene();
    } );

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
    global_state.script(R"(
        print("Hello, World!")
        local vec = Vector3.new(1, 2, 3)
        vec.x = 1
        vec.y = 2
        vec.z = 3
        print(vec.x)
        print(vec.y)
        print(vec.z)
    )");
    
    global_state.script(R"(
        function vector3tostring(vec)
            return "<" .. vec.x .. ", " .. vec.y .. ", " .. vec.z .. ">"
        end

        function printEntity(entity, indent)
            print(indent .. "Entity: " .. entity.name)
            local spatialTransform = SpatialTransform.getFromEntity(entity)
            if spatialTransform then
                local position = spatialTransform.position
                local rotation = spatialTransform.rotation
                local scale = spatialTransform.scale
                local global = spatialTransform.global
                --print(position == nil)

                print(indent .. "    Transform: " .. position:tostring() .. ", " .. rotation:tostring() .. ", " .. scale:tostring())
                print(indent .. "    Global Transform: " .. global:tostring())
            end
            for i = 0, entity:getChildCount() - 1 do
                local child = entity:getChild(i)
                printEntity(child, indent .. "    ")
            end
        end

        function printScene(_scene)
            print("Scene")
            for i = 0, _scene:getEntityCount() - 1 do
                local entity = _scene:getEntity(i)
                printEntity(entity, "    ")
            end
        end

        local scene = createScene()
        local entity1 = Entity.new()
        entity1.name = "Entity1"
        local e1transform = SpatialTransform.new()
        entity1:addComponent(e1transform, "SpatialTransform")
        scene:addEntity(entity1)
        e1transform.position = Vector3.new(1, 2, 3)
        local child1 = Entity.new()
        child1.name = "Child1"
        local c1transform = SpatialTransform.new()
        child1:addComponent(c1transform, "SpatialTransform")
        entity1:addChild(child1)
        c1transform.position = Vector3.new(4, 5, 6)
        local entity2 = Entity.new()
        entity2.name = "Entity2"
        local e2transform = SpatialTransform.new()
        entity2:addComponent(e2transform, "SpatialTransform")
        scene:addEntity(entity2)
        e2transform.position = Vector3.new(7, 8, 9)
        local entity3 = Entity.new()
        entity3.name = "Entity3"
        local e3transform = SpatialTransform.new()
        entity3:addComponent(e3transform, "SpatialTransform")
        local e3camera = Camera.new()
        entity3:addComponent(e3camera, "Camera")
        scene:addEntity(entity3)
        e3transform.position = Vector3.new(0, 0, 1)    
        local entity4 = Entity.new()
        entity4.name = "Entity4"
        local e4transform = SpatialTransform.new()
        entity4:addComponent(e4transform, "SpatialTransform")
        local e4mesh = MeshRenderer.new()
        entity4:addComponent(e4mesh, "MeshRenderer")
        local e4capsule = Capsule.new()
        entity4:addComponent(e4capsule, "Capsule")
        --local e4sphere = Sphere.new()
        --entity4:addComponent(e4sphere, "Sphere")
        --local e4box = Box.new()
        --entity4:addComponent(e4box, "Box")
        --e4box.size = Vector3.new(1, 1, 1)
        scene:addEntity(entity4)
        e4transform.position = Vector3.new(0, 0, -1)

        printScene(scene)
    )");
}

void App::start() {
}

Scene* App::createScene() {
    auto sceneNode = memnew( SceneNode );
    auto scene = sceneNode->getScene();
    add_child(scene->root);
    scene->viewport = get_viewport();
    return scene;
}