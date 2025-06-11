#include "lua_bind.h"

void sunaba::core::bind_packedvector4array(sol::state& lua) {
    lua.new_usertype<PackedVector4Array>("PackedVector4Array",
        sol::constructors<PackedVector4Array(), PackedVector4Array(const PackedVector4Array&), PackedVector4Array(Array)>(),
        "append", &PackedVector4Array::append,
        "appendArray", &PackedVector4Array::append_array,
        "bsearch", &PackedVector4Array::bsearch,
        "clear", &PackedVector4Array::clear,
        "count", &PackedVector4Array::count,
        "duplicate", &PackedVector4Array::duplicate,
        "fill", &PackedVector4Array::fill,
        "find", &PackedVector4Array::find,
        "get", &PackedVector4Array::get,
        "has", &PackedVector4Array::has,
        "insert", &PackedVector4Array::insert,
        "isEmpty", &PackedVector4Array::is_empty,
        "pushBack", &PackedVector4Array::push_back,
        "removeAt", &PackedVector4Array::remove_at,
        "resize", &PackedVector4Array::resize,
        "reverse", &PackedVector4Array::reverse,
        "rfind", &PackedVector4Array::rfind,
        "set", &PackedVector4Array::set,
        "size", &PackedVector4Array::size,
        "slice", &PackedVector4Array::slice,
        "sort", &PackedVector4Array::sort//,
        //sol::meta_function::index, [](const PackedVector4Array& arr, int index) { return arr[index]; },
        //sol::meta_function::new_index, [](PackedVector4Array& arr, int index, const Vector4& value) {
        //    arr.set(index, value);
        //},
        //sol::meta_function::length, &PackedVector4Array::size
    );
}