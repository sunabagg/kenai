#include "system_io_interface.h"

#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/file_access.hpp>

#include "../string_utils.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::core::io {
    void bindSystemIoInterface(sol::state& lua) {
        lua.new_usertype<SystemIoInterface>(
            "SystemIoInterface",
            sol::no_constructor,
            sol::base_classes, sol::bases<IoInterface>(),
            "getFileUri", &SystemIoInterface::getFileUri
        );
    }
    
    std::string SystemIoInterface::loadText(const std::string &path) const {
        std::string realPath = getFilePath(path);
        Ref<FileAccess> file = FileAccess::open(realPath.c_str(), FileAccess::READ);
        if (file == nullptr) {
            return "";
        }
        std::string text = file->get_as_text().utf8().get_data();
        file->close();
        return text;
    }

    void SystemIoInterface::saveText(const std::string &path, const std::string &text) const {
        std::string realPath = getFilePath(path);
        Ref<FileAccess> file = FileAccess::open(realPath.c_str(), FileAccess::WRITE);
        if (file == nullptr) {
            return;
        }
        file->store_string(text.c_str());
        file->close();
    }

    PackedByteArray SystemIoInterface::loadBytes(const std::string &path) const {
        std::string realPath = getFilePath(path);
        Ref<FileAccess> file = FileAccess::open(realPath.c_str(), FileAccess::READ);
        if (file == nullptr) {
            return PackedByteArray();
        }
        PackedByteArray bytes = file->get_buffer(file->get_length());
        file->close();
        return bytes;
    }

    void SystemIoInterface::saveBytes(const std::string &path, const PackedByteArray &bytes) const {
        std::string realPath = getFilePath(path);
        Ref<FileAccess> file = FileAccess::open(realPath.c_str(), FileAccess::WRITE);
        if (file == nullptr) {
            return;
        }
        file->store_buffer(bytes);
        file->close();
    }

    std::vector<std::string> SystemIoInterface::getFileList(const std::string &path, const std::string &extension, const bool recursive) const {
        String pathStr = getFilePath(path).c_str();
        if (StringUtils::endsWith(path, "/")) {
            pathStr = path.substr(0, path.size() - 1).c_str();
        }
        Ref<DirAccess> dir = DirAccess::open(path.c_str());
        if (dir == nullptr) {
            return std::vector<std::string>();
        }
        std::vector<std::string> files;
        
        auto fileList = dir->get_files();
        for (int i = 0; i < fileList.size(); i++) {
            String file = fileList[i];
            if (extension.size() > 0 && !StringUtils::endsWith(file.utf8().get_data(), extension)) {
                continue;
            }
            files.push_back(getFileUri(path + "/" + file.utf8().get_data()));
        }
        auto dirList = dir->get_directories();
        for (int i = 0; i < dirList.size(); i++) {
            String dirName = dirList[i];
            if (recursive) {
                auto subFiles = getFileList(path + "/" + dirName.utf8().get_data(), extension, recursive);
                files.insert(files.end(), subFiles.begin(), subFiles.end());
            }
            if (extension == "" || extension == "/") {
                files.push_back(getFileUri(path + "/" + dirName.utf8().get_data()));
            }
        }

        return files;
    }

    void SystemIoInterface::deleteFile(const std::string &path) const {
        if (StringUtils::endsWith(path, "/")) return;
        Ref<DirAccess> dir = memnew(DirAccess);
        std::string realPath = getFilePath(path);
        dir->remove(realPath.c_str());
    }

    int SystemIoInterface::createDirectory(const std::string &path) const {
        std::string realPath = getFilePath(path);
        Ref<DirAccess> dir = memnew(DirAccess);
        if (!dir->dir_exists(realPath.c_str())) {
            auto err = dir->make_dir(realPath.c_str());
            if (err == OK) {
                return 0;
            }
        }
        return -1;
    }

    void SystemIoInterface::deleteDirectory(const std::string &path) const {
        if (!StringUtils::endsWith(path, "/")) return;
        std::string realPath = getFilePath(path);
        Ref<DirAccess> dir = memnew(DirAccess);
        dir->remove(realPath.c_str());
    }

    bool SystemIoInterface::directoryExists(const std::string &path) const {
        std::string realPath = getFilePath(path);
        Ref<DirAccess> dir = memnew(DirAccess);
        return dir->dir_exists(realPath.c_str());
    }
}

