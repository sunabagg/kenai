#include "zip_io.h"

#include "../string_utils.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::core::io {
    void bindZipIo(sol::state& lua) {
        lua.new_usertype<ZipIo>(
            "ZipIo",
            sol::no_constructor,
            sol::base_classes, sol::bases<BaseObject, IoInterface>(),
        );
    }
} // namespace sunaba::core::io