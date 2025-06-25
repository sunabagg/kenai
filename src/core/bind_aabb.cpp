#include "lua_bind.h"

void lucidware::core::bind_aabb(sol::state& lua) {
    lua.new_usertype<godot::AABB>(
        "AABB",
        sol::constructors<
            AABB(), 
            AABB(Vector3, Vector3)>(),
        "end", sol::property(
            [](AABB& self) { 
                return self.get_end(); 
            }, 
            [](AABB& self, Vector3 value) { 
                self.set_end(value); 
            }
        ),
        "position", &AABB::position,
        "size", &AABB::size,
        "abs", &AABB::abs,
        "encloses", &AABB::encloses,
        "getCenter", &AABB::get_center,
        "getEndpoint", &AABB::get_endpoint,
        "getLongestAxis", &AABB::get_longest_axis,
        "getLongestAxisIndex", &AABB::get_longest_axis_index,
        "getLongestAxisSize", &AABB::get_longest_axis_size, 
        "getShortestAxis", &AABB::get_shortest_axis,
        "getShortestAxisIndex", &AABB::get_shortest_axis_index,
        "getShortestAxisSize", &AABB::get_shortest_axis_size,
        "getSupport", &AABB::get_support,
        "getVolume", &AABB::get_volume,
        "grow", &AABB::grow,
        "hasPoint", &AABB::has_point,
        "hasSurface", &AABB::has_surface,
        "hasVolume", &AABB::has_volume,
        "intersection", &AABB::intersection,
        "intersects", &AABB::intersects,
        "intersectsPlane", &AABB::intersects_plane,
        "intersectsRay", &AABB::intersects_ray,
        "isEqualApprox", &AABB::is_equal_approx,
        //"isFinite", &AABB::is_finite,
        "merge", &AABB::merge,
        "tostring", [](const AABB& a) { return std::string((a.operator String()).utf8().get_data()); }
    );
}