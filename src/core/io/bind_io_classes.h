#ifndef BIND_IO_CLASSES_H
#define BIND_IO_CLASSES_H

#include <sol/sol.hpp>

namespace lucidware::core::io {
    void bindIoClasses(sol::state& lua);
}

#endif //BIND_IO_CLASSES_H