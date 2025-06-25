#include "zip_io.h"

#include "../string_utils.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::core::io {
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

        auto currentDirName = String(path.c_str()).get_file();
        for (int i = 0; i < files.size(); ++i) {
            std::string file = files[i].utf8().get_data();
            auto folderName = String(file.c_str()).get_base_dir().get_file();
            if (folderName != currentDirName) {
                continue; // Skip files not in the current directory
            }
            file = pathUri + file; // Ensure the path is prefixed with the base URI
            if (file.find(path) == 0 && (extension.empty() || StringUtils::endsWith(file, extension))) {
                file_list.push_back(file);
                auto file_dir = String(file.c_str()).get_base_dir();
            }
        }

        if (recursive) {
            for (int i = 0; i < files.size(); ++i) {
                std::string file = files[i].utf8().get_data();
                auto folderName = String(file.c_str()).get_base_dir().get_file();
                if (folderName == currentDirName) {
                    continue; // Skip files in the current directory
                }
                auto folderPath = String(file.c_str()).get_base_dir().utf8().get_data();
                auto subFiles = getFileList(folderPath, extension, recursive);
                file_list.insert(file_list.end(), subFiles.begin(), subFiles.end());
            }
        }

        return file_list;
    }

    bool ZipIo::directoryExists(const std::string &path) const {
        std::string realPath = getFilePath(path);
        PackedStringArray files = zip_reader->get_files();
        for (int i = 0; i < files.size(); ++i) {
            std::string file = files[i].utf8().get_data();
            if (String(file.c_str()).get_base_dir() == String(realPath.c_str())) {
                return true; // Directory exists if any file matches the base directory
            }
        }
        return false; // No files found in the specified directory
    }
} // namespace lucidware::core::io