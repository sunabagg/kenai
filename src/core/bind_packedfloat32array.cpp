#include "lua_bind.h"

void sunaba::core::bind_packedfloat32array(sol::state& lua) {
    lua.new_usertype<PackedFloat32Array>("PackedFloat32Array",
        sol::constructors<PackedFloat32Array(), PackedFloat32Array(const PackedFloat32Array&), PackedFloat32Array(Array)>(),
        "append", &PackedFloat32Array::append,
        "appendArray", &PackedFloat32Array::append_array,
        "bsearch", &PackedFloat32Array::bsearch,
        "clear", &PackedFloat32Array::clear,
        "count", &PackedFloat32Array::count,
        "duplicate", &PackedFloat32Array::duplicate,
        "fill", &PackedFloat32Array::fill,
        "find", &PackedFloat32Array::find,
        "get", &PackedFloat32Array::get,
        "has", &PackedFloat32Array::has,
        "insert", &PackedFloat32Array::insert,
        "isEmpty", &PackedFloat32Array::is_empty,
        "pushBack", &PackedFloat32Array::push_back,
        "removeAt", &PackedFloat32Array::remove_at,
        "resize", &PackedFloat32Array::resize,
        "reverse", &PackedFloat32Array::reverse,
        "rfind", &PackedFloat32Array::rfind,
        "set", &PackedFloat32Array::set,
        "size", &PackedFloat32Array::size,
        "slice", &PackedFloat32Array::slice,
        "sort", &PackedFloat32Array::sort,
        sol::meta_function::index, [](const PackedFloat32Array& arr, int index) { return arr[index]; },
        sol::meta_function::new_index, [](PackedFloat32Array& arr, int index, float value) {
            arr.set(index, value);
        },
        sol::meta_function::length, &PackedFloat32Array::size
    );
}