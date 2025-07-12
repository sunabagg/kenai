#include "bind_binary_classes.h"
#include "byte.h"
#include "binary_data.h"

void kenai::core::io::bindBinaryClasses(sol::state& lua) {
    bindByte(lua);
    bindBinaryData(lua);
}