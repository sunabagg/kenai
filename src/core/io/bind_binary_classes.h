#ifndef BIND_BINARY_CLASSES_H
#define BIND_BINARY_CLASSES_H

#include <sol/sol.hpp>

namespace lucidware::core::io {
    void bindBinaryClasses(sol::state& lua);
}

#endif //BIND_BINARY_CLASSES_H