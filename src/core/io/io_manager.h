#ifndef IO_MANAGER_H
#define IO_MANAGER_H

#include "io_interface.h"

namespace sunaba::core::io {
    void bindIoManager(sol::state& lua);

    class IoManager : public IoInterface {
    public:
        std::vector<IoInterface*> interfaces;

        void add(IoInterface* io);

        void remove(IoInterface* io);

        std::string getFilePath(const std::string &path) const override;

        std::string getFileUri(const std::string &path, const std::string &base_url) const;

        std::string getLuaRequirePath(const std::string &path) const;

        std::string getFilePathFromLuaRequirePath(const std::string &path) const;

        std::string loadText(const std::string &path) const override;

        void saveText(const std::string &path, const std::string &text) const override;

        PackedByteArray loadBytes(const std::string &path) const override;

        void saveBytes(const std::string &path, const PackedByteArray &bytes) const override;

        std::vector<std::string> getFileList(const std::string &path, const std::string &extension = "", const bool recursive = true) const override;

        void deleteFile(const std::string &path) const override;

        int createDirectory(const std::string &path) const override;

        void deleteDirectory(const std::string &path) const override;

        bool directoryExists(const std::string &path) const override;

        IoManager() {}
        ~IoManager() {}
    };
}

#endif