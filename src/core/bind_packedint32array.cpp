#include "lua_bind.h"

void sunaba::core::bind_packedint32array(sol::state& lua) {
    lua.new_usertype<PackedInt32Array>("PackedInt32Array",
        sol::constructors<PackedInt32Array(), PackedInt32Array(const PackedInt32Array&), PackedInt32Array(Array)>(),
        "append", &PackedInt32Array::append,
        "appendArray", &PackedInt32Array::append_array,
        "bsearch", &PackedInt32Array::bsearch,
        "clear", &PackedInt32Array::clear,
        "count", &PackedInt32Array::count,
        "duplicate", &PackedInt32Array::duplicate,
        "fill", &PackedInt32Array::fill,
        "find", &PackedInt32Array::find,
        "get", &PackedInt32Array::get,
        "has", &PackedInt32Array::has,
        "insert", &PackedInt32Array::insert,
        "isEmpty", &PackedInt32Array::is_empty,
        "pushBack", &PackedInt32Array::push_back,
        "removeAt", &PackedInt32Array::remove_at,
        "resize", &PackedInt32Array::resize,
        "reverse", &PackedInt32Array::reverse,
        "rfind", &PackedInt32Array::rfind,
        "set", &PackedInt32Array::set,
        "size", &PackedInt32Array::size,
        "slice", &PackedInt32Array::slice,
        "sort", &PackedInt32Array::sort//,
        //sol::meta_function::index, [](const PackedInt32Array& arr, int index) { return arr[index]; },
        //sol::meta_function::new_index, [](PackedInt32Array& arr, int index, int value) {
        //    arr.set(index, value);
        //},
        //sol::meta_function::length, &PackedInt32Array::size
    );
}