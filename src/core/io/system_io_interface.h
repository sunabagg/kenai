#ifndef SYSTEM_IO_INTERFACE_H
#define SYSTEM_IO_INTERFACE_H

#include "io_interface.h"

namespace lucidfx::core::io {
    void bindSystemIoInterface(sol::state& lua);

    class SystemIoInterface : public IoInterface {
    public:
        virtual std::string getFileUri(const std::string &path) const { return pathUri + path; } 

        std::string loadText(const std::string &path) const override;
        void saveText(const std::string &path, const std::string &text) const override;
        PackedByteArray loadBytes(const std::string &path) const override;
        void saveBytes(const std::string &path, const PackedByteArray &bytes) const override;
        std::vector<std::string> getFileList(const std::string &path, const std::string &extension = "", const bool recursive = true) const override;
        void deleteFile(const std::string &path) const override;
        int createDirectory(const std::string &path) const override;
        void deleteDirectory(const std::string &path) const override;
        bool directoryExists(const std::string &path) const override;


        SystemIoInterface() {}        
        ~SystemIoInterface() {}
    };;
    
}

#endif