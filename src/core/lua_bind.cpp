//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "lua_function_wrapper.h"

using namespace godot;
using namespace newhaven_core;

void newhaven_core::bind_class_to_lua(sol::state& lua, const String& class_name) {
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
                Callable callable = newhaven_core::create_callable_from_lua_function(function);
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

        return sol::make_object(lua, sol::nil_t());
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
            Callable callable = newhaven_core::create_callable_from_lua_function(function);
            obj->connect(signal["name"], callable);
            //newhaven_core::SignalDB::add_signal(obj, signal["name"], callable);
            return callable;
        };

        ut.set(("connect_" + signal_name).utf8().get_data(), connect_func);

        auto disconnect_func = [class_name, signal](godot::Object* obj, sol::variadic_args va) {
            Callable callable = va[0].as<Callable>();
            obj->disconnect(signal["name"], callable);
            //newhaven_core::SignalDB::remove_signal(obj, signal["name"]);
        };

        ut.set(("disconnect_" + signal_name).utf8().get_data(), disconnect_func);
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

void newhaven_core::bind_base_types(sol::state& lua) {
    lua.new_usertype<Vector2>(
        "Vector2",
        sol::constructors<Vector2(), Vector2(float, float)>(),
        "x", &Vector2::x,
        "y", &Vector2::y,
        "normalize", &Vector2::normalize,
        "normalized", &Vector2::normalized,
        "isNormalized", &Vector2::is_normalized,
        "length", &Vector2::length,
        "lengthSquared", &Vector2::length_squared,
        "limitLength", &Vector2::limit_length,
        "min", &Vector2::min,
        "max", &Vector2::max,
        "distanceTo", &Vector2::distance_to,
        "distanceSquaredTo", &Vector2::distance_squared_to,
        "angleTo", &Vector2::angle_to,
        "angleToPoint", &Vector2::angle_to_point,
        "dot", &Vector2::dot,
        "posmod", &Vector2::posmod,
        "posmodv", &Vector2::posmodv,
        "project", &Vector2::project,
        "planeProject", &Vector2::plane_project,
        "lerp", &Vector2::lerp,
        "slerp", &Vector2::slerp,
        "cubicInterpolate", &Vector2::cubic_interpolate,
        "cubicInterpolateInTime", &Vector2::cubic_interpolate_in_time,
        "bezierInterpolate", &Vector2::bezier_interpolate,
        "moveToward", &Vector2::move_toward,
        "slide", &Vector2::slide,
        "bounce", &Vector2::bounce,
        "reflect", &Vector2::reflect,
        "isEqualApprox", &Vector2::is_equal_approx,
        "isZeroApprox", &Vector2::is_zero_approx,
        "angle", &Vector2::angle,
        "abs", &Vector2::abs,
        "rotated", &Vector2::rotated,
        "orthogonal", &Vector2::orthogonal,
        "sign", &Vector2::sign,
        "floor", &Vector2::floor,
        "ceil", &Vector2::ceil,
        "round", &Vector2::round,
        "snapped", &Vector2::snapped,
        "clamp", &Vector2::clamp,
        "aspect", &Vector2::aspect
        );

    lua.new_usertype<godot::Vector3>(
        "Vector3",
        sol::constructors<Vector3(), Vector3(float, float, float)>(),
        "x", &Vector3::x,
        "y", &Vector3::y,
        "z", &Vector3::z,
        "abs", &Vector3::abs,
        "angleTo", &Vector3::angle_to,
        //"bezierDerivative", &Vector3::bezier_derivative,
        "bezierInterpolate", &Vector3::bezier_interpolate,
        "bounce", &Vector3::bounce,
        "ceil", &Vector3::ceil,
        "clamp", &Vector3::clamp,
        //"clampf", &Vector3::clampf,
        "cross", &Vector3::cross,
        "cubicInterpolate", &Vector3::cubic_interpolate,
        "cubicInterpolateInTime", &Vector3::cubic_interpolate_in_time,
        "directionTo", &Vector3::direction_to,
        "distanceSquaredTo", &Vector3::distance_squared_to,
        "distanceTo", &Vector3::distance_to,
        "dot", &Vector3::dot,
        "floor", &Vector3::floor,
        "inverse", &Vector3::inverse,
        "isEqualApprox", &Vector3::is_equal_approx,
        //"isFinite", &Vector3::is_finite,
        "isNormalized", &Vector3::is_normalized,
        "isZeroApprox", &Vector3::is_zero_approx,
        "length", &Vector3::length,
        "lengthSquared", &Vector3::length_squared,
        "limitLength", &Vector3::limit_length,
        "lerp", &Vector3::lerp,
        "max", &Vector3::max,
        "maxAxisIndex", &Vector3::max_axis_index,
        "min", &Vector3::min,
        "minAxisIndex", &Vector3::min_axis_index,
        "moveToward", &Vector3::move_toward,
        "normalize", &Vector3::normalize,
        "normalized", &Vector3::normalized,
        "octahedronDecode", &Vector3::octahedron_decode,
        "octrahedronEncode", &Vector3::octahedron_encode,
        "outer", &Vector3::outer,
        "posmod", &Vector3::posmod,
        "posmodv", &Vector3::posmodv,
        "project", &Vector3::project,
        "reflect", &Vector3::reflect,
        "rotated", &Vector3::rotated,
        "round", &Vector3::round,
        "sign", &Vector3::sign,
        "signedAngleTo", &Vector3::signed_angle_to,
        "slerp", &Vector3::slerp,
        "slide", &Vector3::slide,
        "snapped", &Vector3::snapped
        );
    
    lua.new_usertype<godot::Vector4>(
        "Vector4",
        sol::constructors<Vector4(), Vector4(float, float, float, float)>(),
        "x", &Vector4::x,
        "y", &Vector4::y,
        "z", &Vector4::z,
        "w", &Vector4::w,
        "abs", &Vector4::abs,
        "ceil", &Vector4::ceil,
        "clamp", &Vector4::clamp,
        "cubicInterpolate", &Vector4::cubic_interpolate,
        "cubicInterpolateInTime", &Vector4::cubic_interpolate_in_time,
        "directionTo", &Vector4::direction_to,
        "distanceSquaredTo", &Vector4::distance_squared_to,
        "distanceTo", &Vector4::distance_to,
        "dot", &Vector4::dot,
        "floor", &Vector4::floor,
        "inverse", &Vector4::inverse,
        "isEqualApprox", &Vector4::is_equal_approx,
        //"isFinite", &Vector4::is_finite,
        "isNormalized", &Vector4::is_normalized,
        "isZeroApprox", &Vector4::is_zero_approx,
        "length", &Vector4::length,
        "lengthSquared", &Vector4::length_squared,
        "lerp", &Vector4::lerp,
        "max", &Vector4::max,
        "maxAxisIndex", &Vector4::max_axis_index,
        "min", &Vector4::min,
        "minAxisIndex", &Vector4::min_axis_index,
        "normalized", &Vector4::normalized,
        "posmod", &Vector4::posmod,
        "posmodv", &Vector4::posmodv,
        "round", &Vector4::round,
        "sign", &Vector4::sign,
        "snapped", &Vector4::snapped
    );

    lua.new_usertype<godot::Basis>(
        "Basis",
        sol::constructors<Basis(), Basis(Vector3, Vector3, Vector3)>(),
        "x", &Basis::x,
        "y", &Basis::y,
        "z", &Basis::z,
        "determinant", &Basis::determinant,
        "fromEuler", &Basis::from_euler,
        "fromScale", &Basis::from_scale,
        "getEuler", &Basis::get_euler,
        "getRotationQuaternion", &Basis::get_rotation_quaternion,
        "getScale", &Basis::get_scale,
        "inverse", &Basis::inverse,
        //"isConformal", &Basis::is_conformal,
        "isEqualApprox", &Basis::is_equal_approx,
        //"isFinite", &Basis::is_finite,
        "lookingAt", &Basis::looking_at,
        "orthonormalized", &Basis::orthonormalized,
        "rotated", &Basis::rotated,
        "scaled", &Basis::scaled,
        "slerp", &Basis::slerp,
        "tdotx", &Basis::tdotx,
        "tdoty", &Basis::tdoty,
        "tdotz", &Basis::tdotz,
        "transposed", &Basis::transposed
    );

    lua.new_usertype<godot::Transform3D>(
        "Transform3D",
        sol::constructors<Transform3D(), Transform3D(Vector3, Vector3, Vector3), Transform3D(Basis, Vector3>(),
        "basis", &Transform3D::basis,
        "origin", &Transform3D::origin,
        "affineInverse", &Transform3D::affine_inverse,
        "interpolateWith", &Transform3D::interpolate_with,
        "isEqualApprox", &Transform3D::is_equal_approx,
        "isFinite", &Transform3D::is_finite,
        "lookingAt", &Transform3D::looking_at,
        "orthonormalized", &Transform3D::orthonormalized,
        "rotated", &Transform3D::rotated,
        "rotatedLocal", &Transform3D::rotated_local,
        "scaled", &Transform3D::scaled,
        "scaledLocal", &Transform3D::scaled_local,
        "translated", &Transform3D::translated,
        "translatedLocal", &Transform3D::translated_local
    );
}

void newhaven_core::initialize_lua(sol::state& lua) {
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