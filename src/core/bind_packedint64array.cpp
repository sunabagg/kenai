#include "lua_bind.h"

void sunaba::core::bind_packedint64array(sol::state& lua) {
    lua.new_usertype<PackedInt64Array>("PackedInt64Array",
        sol::constructors<PackedInt64Array(), PackedInt64Array(const PackedInt64Array&), PackedInt64Array(Array)>(),
        "append", &PackedInt64Array::append,
        "appendArray", &PackedInt64Array::append_array,
        "bsearch", &PackedInt64Array::bsearch,
        "clear", &PackedInt64Array::clear,
        "count", &PackedInt64Array::count,
        "duplicate", &PackedInt64Array::duplicate,
        "fill", &PackedInt64Array::fill,
        "find", &PackedInt64Array::find,
        "get", &PackedInt64Array::get,
        "has", &PackedInt64Array::has,
        "insert", &PackedInt64Array::insert,
        "isEmpty", &PackedInt64Array::is_empty,
        "pushBack", &PackedInt64Array::push_back,
        "removeAt", &PackedInt64Array::remove_at,
        "resize", &PackedInt64Array::resize,
        "reverse", &PackedInt64Array::reverse,
        "rfind", &PackedInt64Array::rfind,
        "set", &PackedInt64Array::set,
        "size", &PackedInt64Array::size,
        "slice", &PackedInt64Array::slice,
        "sort", &PackedInt64Array::sort//,
        //sol::meta_function::index, [](const PackedInt64Array& arr, int index) { return arr[index]; },
        //sol::meta_function::new_index, [](PackedInt64Array& arr, int index, int64_t value) {
        //    arr.set(index, value);
        //},
        //sol::meta_function::length, &PackedInt64Array::size
    );
}
