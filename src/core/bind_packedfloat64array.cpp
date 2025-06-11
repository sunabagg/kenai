#include "lua_bind.h"

void sunaba::core::bind_packedfloat64array(sol::state& lua) {
    lua.new_usertype<PackedFloat64Array>("PackedFloat64Array",
        sol::constructors<PackedFloat64Array(), PackedFloat64Array(const PackedFloat64Array&), PackedFloat64Array(Array)>(),
        "append", &PackedFloat64Array::append,
        "appendArray", &PackedFloat64Array::append_array,
        "bsearch", &PackedFloat64Array::bsearch,
        "clear", &PackedFloat64Array::clear,
        "count", &PackedFloat64Array::count,
        "duplicate", &PackedFloat64Array::duplicate,
        "fill", &PackedFloat64Array::fill,
        "find", &PackedFloat64Array::find,
        "get", &PackedFloat64Array::get,
        "has", &PackedFloat64Array::has,
        "insert", &PackedFloat64Array::insert,
        "isEmpty", &PackedFloat64Array::is_empty,
        "pushBack", &PackedFloat64Array::push_back,
        "removeAt", &PackedFloat64Array::remove_at,
        "resize", &PackedFloat64Array::resize,
        "reverse", &PackedFloat64Array::reverse,
        "rfind", &PackedFloat64Array::rfind,
        "set", &PackedFloat64Array::set,
        "size", &PackedFloat64Array::size,
        "slice", &PackedFloat64Array::slice,
        "sort", &PackedFloat64Array::sort,
        sol::meta_function::index, [](const PackedFloat64Array& arr, int index) { return arr[index]; },
        sol::meta_function::new_index, [](PackedFloat64Array& arr, int index, double value) {
            arr.set(index, value);
        },
        sol::meta_function::length, &PackedFloat64Array::size
    );
}