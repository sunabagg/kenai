#ifndef ZIP_IO_H
#define ZIP_IO_H

#include <godot_cpp/classes/zip_reader.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "io_interface.h"

namespace sunaba::core::io {
    void bindZipIo(sol::state& lua);

    class ZipIo : public IoInterface {
    private:
        godot::Ref<godot::ZIPReader> zip_reader;
    public:
        ZipIo(const std::string &path) {
            zip_reader  = godot::Ref<godot::ZIPReader>(memnew(godot::ZIPReader));
            zip_reader->open(path.c_str());
        }
        
        std::string loadText(const std::string &path) const override;
        PackedByteArray loadBytes(const std::string &path) const override;
        void saveBytes(const std::string &path, const PackedByteArray &bytes) const override;
        std::vector<std::string> getFileList(const std::string &path, const std::string &extension = "", const bool recursive = true) const override;
        void deleteFile(const std::string &path) const override;
        int createDirectory(const std::string &path) const override;
        void deleteDirectory(const std::string &path) const override;
        bool directoryExists(const std::string &path) const override;
    };
} // namespace sunaba::core::io 

#endif