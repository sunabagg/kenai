#ifndef CUSTOM_IO_INTERFACE_H
#define CUSTOM_IO_INTERFACE_H

#include <sol/sol.hpp>

#include "io_interface.h"

namespace sunaba::core::io {
    void bindCustomIoInterface(sol::state& lua);

    class CustomIoInterface : public IoInterface {
    private:
        sol::table object = sol::lua_nil;
    public:

        sol::table getObject() {
            return object;
        }

        void setObject(sol::table obj) {
            object = obj;
        }

        std::string getFileUri(const std::string &path) const;
        std::string getFilePath(const std::string &path) const;
        std::string loadText(const std::string &path) const override;
        void saveText(const std::string &path, const std::string &text) const override;
        PackedByteArray loadBytes(const std::string &path) const override;
        void saveBytes(const std::string &path, const PackedByteArray &bytes) const override;
        std::vector<std::string> getFileList(const std::string &path, const std::string &extension = "", const bool recursive = true) const override;
        void deleteFile(const std::string &path) const override;
        int createDirectory(const std::string &path) const override;
        void deleteDirectory(const std::string &path) const override;
        bool directoryExists(const std::string &path) const override;


        CustomIoInterface() {}        
        ~CustomIoInterface() {}
    };
}

#endif