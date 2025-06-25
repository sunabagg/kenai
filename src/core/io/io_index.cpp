#include "io_index.h"

namespace lucidware::core::io {
    std::map<sol::state_view, IoManager*> IoIndex::ioManagers;
}