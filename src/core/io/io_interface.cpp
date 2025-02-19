#include "io_interface.h"

using namespace godot;

void sunaba::core::io::bindIoInterface(sol::state lua) {
    lua.new_usertype<IoInterface>(
        "IoInterface",
        sol::base_classes, sol::bases<BaseObject>(),
        sol::no_constructor,
        "fileUrl", sol::property(
            [](IoInterface& self) { return self.pathUrl; },
            [](IoInterface& self, const std::string &value) { self.pathUrl = value; }
        ),
        "getFilePath", &IoInterface::getFilePath,
        "loadText", &IoInterface::loadText,
        "saveText", &IoInterface::saveText,
        "loadBytes", &IoInterface::loadBytes,
        "saveBytes", &IoInterface::saveBytes,
        "getFileListAll", &IoInterface::getFileListAll,
        "getFileList", &IoInterface::getFileList,
        "fileExists", &IoInterface::fileExists,
        "deleteFile", &IoInterface::deleteFile,
        "moveFile", &IoInterface::moveFile,
        "createDirectory", &IoInterface::createDirectory,
        "deleteDirectory", &IoInterface::deleteDirectory,
        "directoryExists", &IoInterface::directoryExists
    );
}