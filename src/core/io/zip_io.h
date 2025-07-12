#ifndef ZIP_IO_H
#define ZIP_IO_H

#include <godot_cpp/classes/zip_reader.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "io_interface.h"

namespace kenai::core::io {
    void bindZipIo(sol::state& lua);

    class ZipIo : public IoInterface {
    private:
        godot::Ref<godot::ZIPReader> zip_reader;

        godot::Error errorCode = godot::Error::OK;
    public:
        ZipIo(const std::string &path) {
            zip_reader  = godot::Ref<godot::ZIPReader>(memnew(godot::ZIPReader));
            errorCode = zip_reader->open(path.c_str());
        }

        godot::Error getErrorCode() const {
            return errorCode;
        }

        std::string getFilePath(const std::string &path) const override {
            String filePath = String(path.c_str());
            if (filePath.begins_with(pathUri.c_str())) {
                filePath = filePath.replace(pathUri.c_str(), "");
                return filePath.utf8().get_data();
            }
            else {
                return path; // Return the original path if it doesn't match the URI
            }
        }
        
        std::string loadText(const std::string &path) const override;
        PackedByteArray loadBytes(const std::string &path) const override;
        std::vector<std::string> getFileList(const std::string &path, const std::string &extension = "", const bool recursive = true) const override;
        bool directoryExists(const std::string &path) const override;
    };
} // namespace kenai::core::io 

#endif