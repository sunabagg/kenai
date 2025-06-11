#include "lua_bind.h"

void sunaba::core::bind_packedvector2array(sol::state& lua) {
    lua.new_usertype<PackedVector2Array>("PackedVector2Array",
        sol::constructors<PackedVector2Array(), PackedVector2Array(const PackedVector2Array&), PackedVector2Array(Array)>(),
        "append", &PackedVector2Array::append,
        "appendArray", &PackedVector2Array::append_array,
        "bsearch", &PackedVector2Array::bsearch,
        "clear", &PackedVector2Array::clear,
        "count", &PackedVector2Array::count,
        "duplicate", &PackedVector2Array::duplicate,
        "fill", &PackedVector2Array::fill,
        "find", &PackedVector2Array::find,
        "get", &PackedVector2Array::get,
        "has", &PackedVector2Array::has,
        "insert", &PackedVector2Array::insert,
        "isEmpty", &PackedVector2Array::is_empty,
        "pushBack", &PackedVector2Array::push_back,
        "removeAt", &PackedVector2Array::remove_at,
        "resize", &PackedVector2Array::resize,
        "reverse", &PackedVector2Array::reverse,
        "rfind", &PackedVector2Array::rfind,
        "set", &PackedVector2Array::set,
        "size", &PackedVector2Array::size,
        "slice", &PackedVector2Array::slice,
        "sort", &PackedVector2Array::sort//,
        //sol::meta_function::index, [](const PackedVector2Array& arr, int index) { return arr[index]; },
        //sol::meta_function::new_index, [](PackedVector2Array& arr, int index, const Vector2& value) {
        //    arr.set(index, value);
        //},
        //sol::meta_function::length, &PackedVector2Array::size
    );
}
