//
// Created by mintkat on 2/1/25.
//
#include "lua_bind.h"


#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <vector>

using namespace godot;
using namespace sunaba::core;

void sunaba::core::bind_base_types(sol::state& lua) {
    bind_varaint(lua);
    bind_array_list(lua);
    bind_dictionary(lua);
    bind_vector2(lua);
    bind_rect2(lua);
    bind_vector2i(lua);
    bind_rect2i(lua);
    bind_vector3(lua);
    bind_vector3i(lua);
    bind_vector4(lua);
    bind_vector4i(lua);
    bind_quaternion(lua);
    bind_transform3d(lua);
    bind_aabb(lua);

    

    

    

    

    

    lua.new_usertype<godot::Color>(
        "Color",
        sol::constructors<
            Color(), 
            Color(float, float, float),
            Color(float, float, float, float),
            Color(Color, float),
            Color(String),
            Color(String, float)>(),
        "r", &Color::r,
        "g", &Color::g,
        "b", &Color::b,
        "a", &Color::a,
        //"s", &Color::s,
        //"v", &Color::v,
        //"h", &Color::h,
        "blend", &Color::blend,
        "clamp", &Color::clamp,
        "darkened", &Color::darkened,
        "fromHSV", &Color::from_hsv,
        //"fromOkHsl", &Color::from_ok_hsl,
        "fromRGBE9995", &Color::from_rgbe9995,
        "fromString", &Color::from_string,
        "getLuminance", &Color::get_luminance,
        "hex", &Color::hex,
        "hex64", &Color::hex64,
        "html", &Color::html,
        "htmlIsValid", &Color::html_is_valid,
        "inverted", &Color::inverted,
        "isEqualApprox", &Color::is_equal_approx,
        "lerp", &Color::lerp,
        "lightened", &Color::lightened,
        "linearToSrgb", &Color::linear_to_srgb,
        "SrgbToLinear", &Color::srgb_to_linear,
        "toAbgr32", &Color::to_abgr32,
        "toAbgr64", &Color::to_abgr64,
        "toArgb32", &Color::to_argb32,
        "toArgb64", &Color::to_argb64,
        "toHtml", &Color::to_html,
        "toRgba32", &Color::to_rgba32,
        "toRgba64", &Color::to_rgba64,
        "tostring", [](const Color& c) { return std::string((c.operator String()).utf8().get_data()); }
    );
}
