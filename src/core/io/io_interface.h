#ifndef IO_INTERFACE_H
#define IO_INTERFACE_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <string>
#include <vector>
#include <cstddef>
#include <sol/sol.hpp>

#include "../base_object.h"
#include "binary_data.h"

using namespace godot;
using namespace lucidfx::core;

namespace lucidfx::core::io {

    void bindIoInterface(sol::state& lua);

    class IoInterface : public BaseObject {
    public:
        std::string pathUri = "files://";

        virtual std::string getFilePath(const std::string &path) const { return pathUri + path; }

        virtual std::string loadText(const std::string &path) const { return ""; }

        virtual void saveText(const std::string &path, const std::string &text) const {}

        virtual PackedByteArray loadBytes(const std::string &path) const { return PackedByteArray(); }

        virtual void saveBytes(const std::string &path, const PackedByteArray &bytes) const {}

        BinaryData loadBinary(const std::string &path) const {
            PackedByteArray bytes = loadBytes(path);
            return BinaryData(bytes);
        }

        void saveBinary(const std::string &path, const BinaryData &data) const {
            PackedByteArray bytes = data.toPackedByteArray();
            saveBytes(path, bytes);
        }

        std::vector<std::string> getFileListAll(const std::string &extension = "", const bool recursive = true) const {
            return getFileList(pathUri, extension, recursive);
        }

        virtual std::vector<std::string> getFileList(const std::string &path, const std::string &extension = "", const bool recursive = true) const {
            return std::vector<std::string>();
        }

        bool fileExists(const std::string &path) const {
            return loadBytes(path).size() > 0;
        }

        virtual void deleteFile(const std::string &path) const {}

        void moveFile(const std::string &from, const std::string &to) const {
            auto bytes = loadBytes(from);
            saveBytes(to, bytes);
            deleteFile(from);
        }

        virtual int createDirectory(const std::string &path) const { return -1;}

        virtual void deleteDirectory(const std::string &path) const {}

        virtual bool directoryExists(const std::string &path) const { return false; }

        IoInterface() {}

        std::string getLuaRequirePath(const std::string &path) const;

        std::string getFilePathFromLuaRequirePath(const std::string &path) const;
    };
}

#endif //IO_INTERFACE_H