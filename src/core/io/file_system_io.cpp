#include "file_system_io.h"

#include "../string_utils.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::core::io {
    void bindFileSystemIo(sol::state& lua) {
        lua.new_usertype<FileSystemIoReference>(
            "FileSystemIo",
            sol::no_constructor,
            sol::base_classes, sol::bases<SystemIoInterfaceReference>(),
            "basePath", sol::property(
                [](FileSystemIoReference self) { return NativeReference<FileSystemIo>(self)->basePath; }
            ),
            "altPath", sol::property(
                [](FileSystemIoReference self) { return NativeReference<FileSystemIo>(self)->altPath; }
            ),
            "altPath2", sol::property(
                [](FileSystemIoReference self) { return NativeReference<FileSystemIo>(self)->altPath2; }
            )
        );
    }
    
    std::string FileSystemIo::getFileUrl(const std::string &path) const {
        return StringUtils::replace(path, basePath, pathUrl);
    }

    std::string FileSystemIo::getFilePath(const std::string &path) const {
        std::string finalPath;
        if (StringUtils::beginsWith(path, pathUrl))
        {
            finalPath = StringUtils::replace(path, pathUrl, basePath);
        }

        if (StringUtils::contains(finalPath, "\\/"))
        {
            finalPath = StringUtils::replace(finalPath, "\\/", "/");
            finalPath = StringUtils::replace(finalPath, "\\", "/");
        }

        return finalPath;
    }

    FileSystemIo* FileSystemIo::create(std::string basePath, std::string pathUrl) {
        FileSystemIo* io = new FileSystemIo();
        if (!StringUtils::endsWith(basePath, "/")) {
            basePath += "/";
        }
        io->basePath = basePath;
        io->altPath = StringUtils::replace(basePath, "/", "\\");
        io->altPath2 = StringUtils::replace(basePath, "\\", "/");
        io->pathUrl = pathUrl;
        return io;
    }
}