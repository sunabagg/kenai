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

    PackedByteArray ZipIo::loadBytes(const std::string &path) const {
        std::string realPath = getFilePath(path);
        if (!zip_reader->file_exists(realPath.c_str())) {
            return PackedByteArray();
        }
        return zip_reader->read_file(realPath.c_str());
    }

    std::vector<std::string> ZipIo::getFileList(const std::string &path, const std::string &extension, const bool recursive) const {
        PackedStringArray files = zip_reader->get_files();
        std::vector<std::string> file_list;

        for (int i = 0; i < files.size(); ++i) {
            std::string file = files[i].utf8().get_data();
            if (file.find(path) == 0 && (extension.empty() || StringUtils::endsWith(file, extension))) {
                file_list.push_back(file);
            }
        }

        return file_list;
    }
} // namespace sunaba::core::io