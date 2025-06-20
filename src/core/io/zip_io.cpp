#include "zip_io.h"

#include "../string_utils.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::core::io {
    void bindZipIo(sol::state& lua) {
        lua.new_usertype<ZipIo>(
            "ZipIo",
            "new", sol::factories(
                [](const std::string &path) {
                    return new ZipIo(path);
                }
            ),
            sol::base_classes, sol::bases<BaseObject, IoInterface>()
        );
    }

    std::string ZipIo::loadText(const std::string &path) const {
        std::string realPath = getFilePath(path);
        if (!zip_reader->file_exists(realPath.c_str())) {
            return "";
        }
        PackedByteArray bytes = zip_reader->read_file(realPath.c_str());
        if (bytes.size() == 0) {
            return "";
        }
        return String::utf8((const char *)bytes.ptr(), bytes.size()).utf8().get_data();
    }
} // namespace sunaba::core::io