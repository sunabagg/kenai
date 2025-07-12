#include "io_index.h"

namespace kenai::core::io {
    std::map<sol::state_view, IoManager*> IoIndex::ioManagers;
}