#include "lua_bind.h"

void sunaba::core::bind_packedstringarray(sol::state& lua) {
    lua.new_usertype<PackedStringArray>("PackedStringArray",
        sol::constructors<PackedStringArray(), PackedStringArray(const PackedStringArray&), PackedStringArray(Array)>(),
        "append", [](PackedStringArray& arr, const std::string& value) {
            return arr.append(value.c_str());
        },
        "appendArray", &PackedStringArray::append_array,
        "bsearch", &PackedStringArray::bsearch,
        "clear", &PackedStringArray::clear,
        "count", &PackedStringArray::count,
        "duplicate", &PackedStringArray::duplicate,
        "fill", &PackedStringArray::fill,
        "find", &PackedStringArray::find,
        "get", &PackedStringArray::get,
        "has", &PackedStringArray::has,
        "insert", &PackedStringArray::insert,
        "isEmpty", &PackedStringArray::is_empty,
        "pushBack", &PackedStringArray::push_back,
        "removeAt", &PackedStringArray::remove_at,
        "resize", &PackedStringArray::resize,
        "reverse", &PackedStringArray::reverse,
        "rfind", &PackedStringArray::rfind,
        "set", &PackedStringArray::set,
        "size", &PackedStringArray::size,
        "slice", &PackedStringArray::slice,
        "sort", &PackedStringArray::sort,
        sol::meta_function::index, [](const PackedStringArray& arr, int index) { return arr[index]; },
        sol::meta_function::new_index, [](PackedStringArray& arr, int index, const String& value) {
            arr.set(index, value);
        },
        sol::meta_function::length, &PackedStringArray::size
    );
}