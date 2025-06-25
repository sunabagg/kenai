#include "lua_bind.h"

void lucidfx::core::bind_rect2(sol::state& lua) {
    lua.new_usertype<Rect2>(
        "Rect2",
        sol::constructors<
            Rect2(), 
            Rect2(Rect2i),
            Rect2(Vector2, Vector2), 
            Rect2(float, float, float, float)>(),
            "end", sol::property(
                [](Rect2& self) { 
                    return self.get_end(); 
                }, 
                [](Rect2& self, Vector2 value) { 
                    self.set_end(value); 
                }
            ),
            "position", &Rect2::position,
            "size", &Rect2::size,
            "abs", &Rect2::abs,
            "encloses", &Rect2::encloses,
            "expand", &Rect2::expand,
            "getArea", &Rect2::get_area,
            "getCenter", &Rect2::get_center,
            "grow", &Rect2::grow,
            "growIndividual", &Rect2::grow_individual,
            "growSide", &Rect2::grow_side,
            "hasArea", &Rect2::has_area,
            "hasPoint", &Rect2::has_point,
            "intersection", &Rect2::intersection,
            "intersects", &Rect2::intersects,
            "isEqualApprox", &Rect2::is_equal_approx,
            //"isFinite", &Rect2::is_finite,
            "merge", &Rect2::merge,
            "tostring", [](const Rect2& r) { return std::string((r.operator String()).utf8().get_data()); }
    );
}