#include "lua_bind.h"

void lucidfx::core::bind_array_list(sol::state& lua) {
    lua.new_usertype<Array>("ArrayList",
        sol::constructors<Array()>(),
        "append", &Array::append,
        "appendArray", &Array::append_array,
        "assign", &Array::assign,
        "back", &Array::back,
        "bsearch", &Array::bsearch,
        "clear", &Array::clear,
        "count", &Array::count,
        "duplicate", &Array::duplicate,
        "erase", &Array::erase,
        "fill", &Array::fill,
        "filter", &Array::filter,
        "find", &Array::find,
        "front", &Array::front,
        "get", &Array::get,
        "has", &Array::has,
        "hash", &Array::hash,
        "insert", &Array::insert,
        "isEmpty", &Array::is_empty,
        "isReadOnly", &Array::is_read_only,
        "makeReadOnly", &Array::make_read_only,
        "max", &Array::max,
        "min", &Array::min,
        "pickRandom", &Array::pick_random,
        "popAt", &Array::pop_at,
        "popBack", &Array::pop_back,
        "popFront", &Array::pop_front,
        "pushBack", &Array::push_back,
        "pushFront", &Array::push_front,
        "removeAt", &Array::remove_at,
        "resize", &Array::resize,
        "reverse", &Array::reverse,
        "rfind", &Array::rfind,
        "set", &Array::set,
        "shuffle", &Array::shuffle,
        "size", &Array::size,
        "slice", &Array::slice,
        "sort", &Array::sort,
        sol::meta_function::index, [](Array& arr, int index) { return arr[index]; },
        sol::meta_function::new_index, [](Array& arr, int index, const Variant& value) {
            arr.set(index, value);
        },
        sol::meta_function::length, &Array::size,
        "__pairs", [](Array& arr) {
            return sol::as_function([&arr, i = 0](sol::this_state s) mutable -> std::tuple<sol::object, sol::object> {
                if (i < arr.size()) {
                    return { sol::make_object(s, i), sol::make_object(s, arr[i++]) };
                } else {
                    return { sol::lua_nil, sol::lua_nil };
                }
            });
        },
        "__ipairs", [](Array& arr) {
            return sol::as_function([](sol::this_state s, Array& a, int i) -> std::tuple<sol::object, sol::object> {
                i++;
                if (i <= a.size()) {
                    return { sol::make_object(s, i), sol::make_object(s, a[i - 1]) };
                }
                return { sol::lua_nil, sol::lua_nil };
            });
        },
        sol::meta_function::to_string, [](const Array& arr) {
            return "<Array size=" + std::to_string(arr.size()) + ">";
        }
        
    );
}