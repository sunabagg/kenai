#include "custom_io_interface.h"

namespace sunaba::core::io {
    void bindCustomIoInterface(sol::state& lua) {
        lua.new_usertype<CustomIoInterface>(
            "CustomIoInterface",
            sol::no_constructor,
            sol::base_classes, sol::bases<BaseObject, IoInterface>(),
            "getFileUri", &CustomIoInterface::getFileUri,
            "object", sol::property(
                &CustomIoInterface::getObject,
                &CustomIoInterface::setObject
            )
        );
    }

    std::string CustomIoInterface::getFileUri(const std::string &path) const {
        if (object != sol::lua_nil) {
            if (object["getFileUri"].is<sol::function>() == false) {
                return "";
            }
            auto func = object["getFileUri"].get<sol::function>();
            if (func) {
                auto result = func.call(path);
                std::string resStr = result.get<std::string>();
                return resStr;
            }
        }
        return "";
    }

    std::string CustomIoInterface::getFilePath(const std::string &path) const {
        if (object != sol::lua_nil) {
            if (object["getFilePath"].is<sol::function>() == false) {
                return "";
            }
            auto func = object["getFilePath"].get<sol::function>();
            if (func) {
                auto result = func.call(path);
                std::string resStr = result.get<std::string>();
                return resStr;
            }
        }
        return pathUri + path; // Fallback to default behavior
    }

    std::string CustomIoInterface::loadText(const std::string &path) const {
        if (object != sol::lua_nil) {
            if (object["loadText"].is<sol::function>() == false) {
                return "";
            }
            auto func = object["loadText"].get<sol::function>();
            if (func) {
                auto result = func.call(path);
                std::string resStr = result.get<std::string>();
                return resStr;
            }
        }
        return IoInterface::loadText(path);
    }

    void CustomIoInterface::saveText(const std::string &path, const std::string &text) const {
        if (object != sol::lua_nil) {
            if (object["saveText"].is<sol::function>() == false) {
                return;
            }
            auto func = object["saveText"].get<sol::function>();
            if (func) {
                func.call(path, text);
                return;
            }
        }
        IoInterface::saveText(path, text);
    }

    PackedByteArray CustomIoInterface::loadBytes(const std::string &path) const {
        if (object != sol::lua_nil) {
            if (object["loadBytes"].is<sol::function>() == false) {
                return PackedByteArray();
            }
            auto func = object["loadBytes"].get<sol::function>();
            if (func) {
                auto result = func.call(path);
                BinaryData* bytesRes = result.get<BinaryData*>();
                if (bytesRes) {
                    return bytesRes->toPackedByteArray();
                }
            }
        }
        return IoInterface::loadBytes(path);
    }

    void CustomIoInterface::saveBytes(const std::string &path, const PackedByteArray &bytes) const {
        if (object != sol::lua_nil) {
            if (object["saveBytes"].is<sol::function>() == false) {
                return;
            }
            auto func = object["saveBytes"].get<sol::function>();
            if (func) {
                func.call(path, new BinaryData(bytes));
                return;
            }
        }
        IoInterface::saveBytes(path, bytes);
    }

    std::vector<std::string> CustomIoInterface::getFileList(const std::string &path, const std::string &extension, const bool recursive) const {
        if (object != sol::lua_nil) {
            if (object["getFileList"].is<sol::function>() == false) {
                return {};
            }
            auto func = object["getFileList"].get<sol::function>();
            if (func) {
                auto result = func.call(path, extension, recursive);
                return result.get<std::vector<std::string>>();
            }
        }
        return IoInterface::getFileList(path, extension, recursive);
    }

    void CustomIoInterface::deleteFile(const std::string &path) const {
        if (object != sol::lua_nil) {
            if (object["deleteFile"].is<sol::function>() == false) {
                return;
            }
            auto func = object["deleteFile"].get<sol::function>();
            if (func) {
                func.call(path);
                return;
            }
        }
        IoInterface::deleteFile(path);
    }
}