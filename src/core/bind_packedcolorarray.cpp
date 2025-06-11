#include "lua_bind.h"

void sunaba::core::bind_packedcolorarray(sol::state& lua) {
    lua.new_usertype<PackedColorArray>("PackedColorArray",
        sol::constructors<PackedColorArray(), PackedColorArray(const PackedColorArray&), PackedColorArray(Array)>(),
        "append", &PackedColorArray::append,
        "appendArray", &PackedColorArray::append_array,
        "bsearch", &PackedColorArray::bsearch,
        "clear", &PackedColorArray::clear,
        "count", &PackedColorArray::count,
        "duplicate", &PackedColorArray::duplicate,
        "fill", &PackedColorArray::fill,
        "find", &PackedColorArray::find,
        "get", &PackedColorArray::get,
        "has", &PackedColorArray::has,
        "insert", &PackedColorArray::insert,
        "isEmpty", &PackedColorArray::is_empty,
        "pushBack", &PackedColorArray::push_back,
        "removeAt", &PackedColorArray::remove_at,
        "resize", &PackedColorArray::resize,
        "reverse", &PackedColorArray::reverse,
        "rfind", &PackedColorArray::rfind,
        "set", &PackedColorArray::set,
        "size", &PackedColorArray::size,
        "slice", &PackedColorArray::slice,
        "sort", &PackedColorArray::sort,
        sol::meta_function::index, [](const PackedColorArray& arr, int index) { return arr[index]; },
        sol::meta_function::new_index, [](PackedColorArray& arr, int index, const Color& value) {
            arr.set(index, value);
        },
        sol::meta_function::length, &PackedColorArray::size
    );
}