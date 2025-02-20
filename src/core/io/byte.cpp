#include "byte.h"

void sunaba::core::io ::bindByte(sol::state& lua) {
    lua.new_usertype<Byte>("Byte",
        sol::constructors<Byte(uint8_t*), Byte(double), Byte(float), Byte(int)>(),
        "getInt", &Byte::getInt,
        "getFloat", &Byte::getFloat,
        "getDouble", &Byte::getDouble
    );
}