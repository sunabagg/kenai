#include "lua_bind.h"

void sunaba::core::bind_packedstringarray(sol::state& lua) {
    lua.new_usertype<PackedStringArray>("PackedStringArray",
        sol::constructors<PackedStringArray(), PackedStringArray(const PackedStringArray&), PackedStringArray(Array)>(),
        "append", [](PackedStringArray& arr, const std::string& value) {
            return arr.append(value.c_str());
        },
        "appendArray", &PackedStringArray::append_array,
        "bsearch", [](PackedStringArray& arr, const std::string& value, bool before = true) {
            return arr.bsearch(value.c_str(), before);
        },
        "clear", &PackedStringArray::clear,
        "count", [](PackedStringArray& arr, const std::string& value) {
            return arr.count(value.c_str());
        },
        "duplicate", &PackedStringArray::duplicate,
        "fill", [](PackedStringArray& arr, const std::string& value) {
            arr.fill(value.c_str());
        },
        "find", [](PackedStringArray& arr, const std::string& value) {
            return arr.find(value.c_str());
        },
        "get", [](const PackedStringArray& arr, int index) {
            return std::string(arr.get(index).utf8().get_data());
        },
        "has", [](PackedStringArray& arr, const std::string& value) {
            return arr.has(value.c_str());
        },
        "insert", [](PackedStringArray& arr, int index, const std::string& value) {
            return arr.insert(index, value.c_str());
        },
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