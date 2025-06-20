#include "file_system_io.h"

#include "../string_utils.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::core::io {
    void bindFileSystemIo(sol::state& lua) {
        lua.new_usertype<FileSystemIo>(
            "FileSystemIo",
            sol::no_constructor,
            sol::base_classes, sol::bases<SystemIoInterface>(),
            "basePath", sol::property(
                [](FileSystemIo& self) { return self.basePath; }
            ),
            "altPath", sol::property(
                [](FileSystemIo& self) { return self.altPath; }
            ),
            "altPath2", sol::property(
                [](FileSystemIo& self) { return self.altPath2; }
            ),
            "getFileUri", &FileSystemIo::getFileUri,
            "getFilePath", &FileSystemIo::getFilePath
        );
    }
    
    std::string FileSystemIo::getFileUri(const std::string &path) const {
        return StringUtils::replace(path, basePath, pathUri);
    }

    std::string FileSystemIo::getFilePath(const std::string &path) const {
        std::string finalPath;
        if (StringUtils::beginsWith(path, pathUri))
        {
            finalPath = StringUtils::replace(path, pathUri, basePath);
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
        io->pathUri = pathUrl;
        return io;
    }
}