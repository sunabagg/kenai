#ifndef ZIP_IO_H
#define ZIP_IO_H

#include <godot_cpp/classes/zip_reader.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <archive.h>

#include "io_interface.h"

namespace sunaba::core::io {
    void bindZipIo(sol::state& lua);

    class ZipIo : public IoInterface {
    private:
        godot::Ref<godot::ZIPReader> zip_reader;

        godot::Error errorCode = godot::Error::OK;

        struct archive* a;

        int r;
    public:
        ZipIo(const std::string &path) {
            auto fileAccess = godot::FileAccess::open(path.c_str(), FileAccess::ModeFlags::READ);
            auto byteArray = fileAccess->get_buffer(fileAccess->get_length());
            fileAccess->close();
            BinaryData* bytes = new BinaryData(byteArray);
            loadArchive(bytes);
        }

        ZipIo(PackedByteArray byteArray) {
            BinaryData* bytes = new BinaryData(byteArray);
            loadArchive(bytes);
        }

        ZipIo(BinaryData* bytes) {
            loadArchive(bytes)
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

        void loadArchive(BinaryData* bytes) {
            std::vector<uint8_t> bufferVec = bytes->toVector();
            archive_read_support_format_zip(a);
            r = archive_read_open_memory(a, bufferVec.data(), bufferVec.size());
            if (r != ARCHIVE_OK) {
                errorCode = Error::FAILED;
            }
        }
        
        std::string loadText(const std::string &path) const override;
        PackedByteArray loadBytes(const std::string &path) const override;
        std::vector<std::string> getFileList(const std::string &path, const std::string &extension = "", const bool recursive = true) const override;
        bool directoryExists(const std::string &path) const override;
    };
} // namespace sunaba::core::io 

#endif