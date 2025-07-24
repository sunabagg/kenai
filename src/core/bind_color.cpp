#include "lua_bind.h"

void sunaba::core::bind_color(sol::state& lua) {
    lua.new_usertype<godot::Color>(
        "Color",
        sol::constructors<
            Color(), 
            Color(float, float, float),
            Color(float, float, float, float),
            Color(Color, float)>(),
        "r", &Color::r,
        "g", &Color::g,
        "b", &Color::b,
        "a", &Color::a,
        "code", sol::factories(
            [](const std::string& str) {
                return godot::Color(str.c_str());
            },
            [](const std::string& str, float alpha) {
                return godot::Color(str.c_str(), alpha);
            }
        ),
        //"s", &Color::s,
        //"v", &Color::v,
        //"h", &Color::h,
        "blend", &Color::blend,
        "clamp", &Color::clamp,
        "darkened", &Color::darkened,
        "fromHSV", &Color::from_hsv,
        //"fromOkHsl", &Color::from_ok_hsl,
        "fromRGBE9995", &Color::from_rgbe9995,
        "fromString", [](const std::string& str, const Color& default_color = Color()) {
            return godot::Color::from_string(str.c_str(), default_color);
        },
        "getLuminance", &Color::get_luminance,
        "hex", &Color::hex,
        "hex64", &Color::hex64,
        "html", [](const std::string& str) {
            return godot::Color::html(str.c_str());
        },
        "htmlIsValid", [](const std::string& str) {
            return godot::Color::html_is_valid(str.c_str());
        },
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
        "toHtml", sol::factories(
            [](const Color& c) {
                return std::string(c.to_html().utf8().get_data());
            },
            [](const Color& c, bool alpha) {
                return std::string(c.to_html(alpha).utf8().get_data());
            }
        ),
        "toRgba32", &Color::to_rgba32,
        "toRgba64", &Color::to_rgba64,
        "tostring", [](const Color& c) { return std::string((c.operator String()).utf8().get_data()); }
    );
}