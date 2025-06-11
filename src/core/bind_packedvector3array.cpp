#include "lua_bind.h"


void sunaba::core::bind_packedvector3array(sol::state& lua) {
    lua.new_usertype<PackedVector3Array>("PackedVector3Array",
        sol::constructors<PackedVector3Array(), PackedVector3Array(const PackedVector3Array&), PackedVector3Array(Array)>(),
        "append", &PackedVector3Array::append,
        "appendArray", &PackedVector3Array::append_array,
        "bsearch", &PackedVector3Array::bsearch,
        "clear", &PackedVector3Array::clear,
        "count", &PackedVector3Array::count,
        "duplicate", &PackedVector3Array::duplicate,
        "fill", &PackedVector3Array::fill,
        "find", &PackedVector3Array::find,
        "get", &PackedVector3Array::get,
        "has", &PackedVector3Array::has,
        "insert", &PackedVector3Array::insert,
        "isEmpty", &PackedVector3Array::is_empty,
        "pushBack", &PackedVector3Array::push_back,
        "removeAt", &PackedVector3Array::remove_at,
        "resize", &PackedVector3Array::resize,
        "reverse", &PackedVector3Array::reverse,
        "rfind", &PackedVector3Array::rfind,
        "set", &PackedVector3Array::set,
        "size", &PackedVector3Array::size,
        "slice", &PackedVector3Array::slice,
        "sort", &PackedVector3Array::sort//,
        //sol::meta_function::index, [](const PackedVector3Array& arr, int index) { return arr[index]; },
        //sol::meta_function::new_index, [](PackedVector3Array& arr, int index, const Vector3& value) {
        //    arr.set(index, value);
        //},
        //sol::meta_function::length, &PackedVector3Array::size
    );
}