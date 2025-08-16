#include "io_manager.h"

#include "system_io_interface.h"
#include "file_system_io.h"
#include "../string_utils.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::core::io {
    void bindIoManager(sol::state& lua) {
        lua.new_usertype<IoManager>(
            "IoManager",
            "new", sol::factories([]() {
                return new IoManager();
            }),
            sol::base_classes, sol::bases<IoInterface>(),
            // total hack
            "add", sol::factories(
                &IoManager::add,
                [](IoManager* ioman, FileSystemIo* fsio) {
                    ioman->add(fsio);
                }
            ),
            "remove", &IoManager::remove,
            "getFileUri", &IoManager::getFileUri
        );
    }

    void IoManager::add(IoInterface* io) {
        interfaces.push_back(io);
    }

    void IoManager::remove(IoInterface* io) {
        for (auto it = interfaces.begin(); it != interfaces.end(); ++it) {
            if (*it == io) {
                interfaces.erase(it);
                return;
            }
        }
    }

    std::string IoManager::getFilePath(const std::string &path) const {
        for (auto& io : interfaces) {
            if (io->fileExists(path)) {
                return io->getFilePath(path);
            }
        }
        return path;
    }

    std::string IoManager::getFileUri(const std::string &path) const {
        for (auto& io : interfaces) {
            if (dynamic_cast<SystemIoInterface*>(io) != nullptr) {
                SystemIoInterface* sio = dynamic_cast<SystemIoInterface*>(io);
                if (sio != nullptr) {
                    std::string uri = sio->getFileUri(path);
                    if (uri != "") return uri;
                }
            }
        }
        return "";
    }

    std::string IoManager::loadText(const std::string &path) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                return io->loadText(path);
            }
        }
        return "";
    }

    void IoManager::saveText(const std::string &path, const std::string &text) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                io->saveText(path, text);
                return;
            }
        }
    }

    PackedByteArray IoManager::loadBytes(const std::string &path) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                return io->loadBytes(path);
            }
        }
        return PackedByteArray();
    }

    void IoManager::saveBytes(const std::string &path, const PackedByteArray &bytes) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                io->saveBytes(path, bytes);
                return;
            }
        }
    }

    std::vector<std::string> IoManager::getFileList(const std::string &path, const std::string &extension, const bool recursive) const {
        std::vector<std::string> files;
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                auto list = io->getFileList(path, extension, recursive);
                files.insert(files.end(), list.begin(), list.end());
            }
        }
        return files;
    }

    void IoManager::deleteFile(const std::string &path) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                io->deleteFile(path);
                return;
            }
        }
    }

    int IoManager::createDirectory(const std::string &path) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                return io->createDirectory(path);
            }
        }
        return 0;
    }

    void IoManager::deleteDirectory(const std::string &path) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                io->deleteDirectory(path);
                return;
            }
        }
    }

    bool IoManager::directoryExists(const std::string &path) const {
        for (auto& io : interfaces) {
            if (StringUtils::beginsWith(path, io->pathUri)) {
                return io->directoryExists(path);
            }
        }
        return false;
    }

    
}