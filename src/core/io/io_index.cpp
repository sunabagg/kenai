#include "io_index.h"

namespace lucidfx::core::io {
    std::map<sol::state_view, IoManager*> IoIndex::ioManagers;
}