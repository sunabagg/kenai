#include "lua_bind.h"

void lucidfx::core::bind_rect2i(sol::state &lua) {
    lua.new_usertype<godot::Rect2i>(
        "Rect2i", 
        sol::constructors<
            Rect2i(), 
            Rect2i(Vector2i, Vector2i),
            Rect2i(Rect2),
            Rect2i(int, int, int, int)>(),
            "position", &Rect2i::position, 
            "size", &Rect2i::size,
            "end", sol::property(
                [](Rect2i& self) {
                    return self.get_end();
                },
                [](Rect2i& self, Vector2i value) {
                    self.set_end(value);
                }
            ),
            "abs", &Rect2i::abs,
            "encloses", &Rect2i::encloses,
            "expand", &Rect2i::expand,
            "getArea", &Rect2i::get_area,
            "getCenter", &Rect2i::get_center,
            "grow", &Rect2i::grow,
            "growSide", &Rect2i::grow_side,
            "hasArea", &Rect2i::has_area,
            "hasPoint", &Rect2i::has_point,
            "intersection", &Rect2i::intersection,
            "intersects", &Rect2i::intersects,
            "tostring", [](const Rect2i& r) { return std::string((r.operator String()).utf8().get_data()); }
            //"isEqualApprox", &Rect2i::is_equal_approx,
    );
}