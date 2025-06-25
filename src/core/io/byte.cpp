#include "byte.h"

void lucidware::core::io ::bindByte(sol::state& lua) {
    lua.new_usertype<Byte>("Byte",
        //sol::constructors<Byte(), Byte(double), Byte(int)>(),
        "new", sol::factories(
            []() { return new Byte(); },
            [](double value) { return new Byte(value); },
            [](int value) { return new Byte(value); }
        ),
        "getInt", &Byte::getInt,
        "getFloat", &Byte::getDouble,
        "setInt", &Byte::setInt,
        "setFloat", &Byte::setDouble
    );
}