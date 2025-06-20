#include "binary_data.h"

void sunaba::core::io::bindBinaryData(sol::state& lua) {
    lua.new_usertype<BinaryData>("BinaryData",
        //sol::constructors<BinaryData(), BinaryData(const sol::table)>(),
        "new", sol::factories(
            []() { return new BinaryData(); },
            [](const sol::table& table) { return new BinaryData(table); }
        ),
        "size", &BinaryData::size,
        "get", &BinaryData::get,
        "set", &BinaryData::set,
        "resize", &BinaryData::resize,
        "append", &BinaryData::append,
        "insert", &BinaryData::insert,
        "toTable", &BinaryData::toTable
    );
}