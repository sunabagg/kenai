#ifndef BIND_INPUT_CLASSES_H
#define BIND_INPUT_CLASSES_H

#include <sol/sol.hpp>

namespace kenai::input {
    void bindInputClasses(sol::state& lua);
}

#endif // BIND_INPUT_CLASSES_H