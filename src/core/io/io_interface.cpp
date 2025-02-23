#include "io_interface.h"

using namespace godot;

void sunaba::core::io::bindIoInterface(sol::state& lua) {
    lua.new_usertype<IoInterfaceReference>(
        "IoInterface",
        sol::no_constructor,
        sol::base_classes, sol::bases<BaseReference>(),
        "fileUrl", sol::property(
            [](IoInterfaceReference self) { return NativeReference<IoInterface>(self)->pathUrl; },
            [](IoInterfaceReference self, const std::string &value) { NativeReference<IoInterface>(self)->pathUrl = value; }
        ),
        "getFilePath", [](IoInterfaceReference self, const std::string &path) { return NativeReference<IoInterface>(self)->getFilePath(path); },
        "loadText", [](IoInterfaceReference self, const std::string &path) { return NativeReference<IoInterface>(self)->loadText(path); },
        "saveText", [](IoInterfaceReference self, const std::string &path, std::string &text) { NativeReference<IoInterface>(self)->saveText(path, text); },
        "loadBinary", [](IoInterfaceReference self, const std::string &path) { return NativeReference<IoInterface>(self)->loadBinary(path); },
        "saveBinary", [](IoInterfaceReference self, const std::string &path, const BinaryData &data) { NativeReference<IoInterface>(self)->saveBinary(path, data); },
        "getFileListAll", [](IoInterfaceReference self, const std::string &extension, const bool recursive) { return NativeReference<IoInterface>(self)->getFileListAll(extension, recursive); },
        "getFileList", [](IoInterfaceReference self, const std::string &path, const std::string &extension, const bool recursive) { return NativeReference<IoInterface>(self)->getFileList(path, extension, recursive); },
        "fileExists", [](IoInterfaceReference self, const std::string &path) { return NativeReference<IoInterface>(self)->fileExists(path); },
        "deleteFile", [](IoInterfaceReference self, const std::string &path) { NativeReference<IoInterface>(self)->deleteFile(path); },
        "moveFile", [](IoInterfaceReference self, const std::string &src, const std::string &dst) { return NativeReference<IoInterface>(self)->moveFile(src, dst); },
        "createDirectory", [](IoInterfaceReference self, const std::string &path) { return NativeReference<IoInterface>(self)->createDirectory(path); },
        "deleteDirectory", [](IoInterfaceReference self, const std::string &path) { NativeReference<IoInterface>(self)->deleteDirectory(path); },
        "directoryExists", [](IoInterfaceReference self, const std::string &path) { return NativeReference<IoInterface>(self)->directoryExists(path); }
    );
}