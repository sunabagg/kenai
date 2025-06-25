#ifndef FILE_SYSTEM_IO_H
#define FILE_SYSTEM_IO_H
#include "system_io_interface.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::core::io {
    void bindFileSystemIo(sol::state& lua);

    class FileSystemIo : public SystemIoInterface {
    public:

        std::string basePath;
        std::string altPath;
        std::string altPath2;

        FileSystemIo() {
            basePath = "res://";
            altPath = "res://";
            altPath2 = "res://";
        }

        static FileSystemIo* create(std::string basePath, std::string pathUrl);

        std::string getFileUri(const std::string &path) const override;
        std::string getFilePath(const std::string &path) const override;
    };
}
#endif //FILE_SYSTEM_IO_H