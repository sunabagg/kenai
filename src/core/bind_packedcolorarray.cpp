#include "lua_bind.h"

void sunaba::core::bind_packedcolorarray(sol::state& lua) {
    lua.new_usertype<PackedColorArray>("PackedColorArray",
        sol::constructors<PackedColorArray()>(),
        "append", &PackedColorArray::append,
        "appendArray", &PackedColorArray::append_array,
        "bsearch", &PackedColorArray::bsearch,
        "clear", &PackedColorArray::clear,
        "count", &PackedColorArray::count,
        "duplicate", &PackedColorArray::duplicate,
        "fill", &PackedColorArray::fill,
        "get", &PackedColorArray::get,
        "has", &PackedColorArray::has,
        "insert", &PackedColorArray::insert,
        "isEmpty", &PackedColorArray::is_empty,
        "pushBack", &PackedColorArray::push_back,
        "removeAt", &PackedColorArray::remove_at,
        "resize", &PackedColorArray::resize,
        "reverse", &PackedColorArray::reverse,
        "set", &PackedColorArray::set,
        "size", &PackedColorArray::size,
        sol::meta_function::index, [](const PackedColorArray& arr, int index) { return arr[index]; },
        sol::meta_function::new_index, [](PackedColorArray& arr, int index, const Color& value) {
            arr.set(index, value);
        },
        sol::meta_function::length, &PackedColorArray::size
    );
}