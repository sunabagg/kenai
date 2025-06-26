#include "file_dialog.h"

namespace sunaba::desktop {
    void FileDialogSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("dir_selected", "dir"), &FileDialogSignalWrapper::dir_selected);
        ClassDB::bind_method(D_METHOD("file_selected", "path"), &FileDialogSignalWrapper::file_selected);
        ClassDB::bind_method(D_METHOD("filename_filter_changed", "filter"), &FileDialogSignalWrapper::filename_filter_changed);
        ClassDB::bind_method(D_METHOD("files_selected", "paths"), &FileDialogSignalWrapper::file_selected);
    }

    void FileDialogSignalWrapper::dir_selected(const String& dir) {
        if (element != nullptr) {
            Array args;
            args.append(dir);
            element->dirSelectedEvent->emit(args);
        }
    }

    void FileDialogSignalWrapper::file_selected(const String& path) {
        if (element != nullptr) {
            Array args;
            args.append(path);
            element->fileSelectedEvent->emit(args);
        }
    }

    void FileDialogSignalWrapper::filename_filter_changed(const String& filter) {
        if (element == nullptr) {
            Array args;
            args.append(filter);
            element->filenameFilterChangedEvent->emit(args);
        }
    }

    void FileDialogSignalWrapper::files_selected(const PackedStringArray& paths) {
        if (element != nullptr) {
            Array args;
            args.append(paths);
            element->filesSelectedEvent->emit(args);
        }
    }

    void bindFileDialog(sol::state& lua) {
        lua.new_usertype<FileDialog>("FileDialog",
            "new", sol::factories(
                []() { return new FileDialog(); }
            ),
            "access", sol::property(
                &FileDialog::getAccess,
                &FileDialog::setAccess
            ),
            "currentDir", sol::property(
                &FileDialog::getCurrentDir,
                &FileDialog::setCurrentDir
            ),
            "currentFile", sol::property(
                &FileDialog::getCurrentFile,
                &FileDialog::setCurrentFile
            ),
            "currentPath", sol::property(
                &FileDialog::getCurrentPath,
                &FileDialog::setCurrentPath
            ),
            "fileMode", sol::property(
                &FileDialog::getFileMode,
                &FileDialog::setFileMode
            ),
            "filenameFilter", sol::property(
                &FileDialog::getFilenameFilter,
                &FileDialog::setFilenameFilter
            ),
            "optionCount", sol::property(
                &FileDialog::getOptionCount,
                &FileDialog::setOptionCount
            ),
            "rootSubfolder", sol::property(
                &FileDialog::getRootSubfolder,
                &FileDialog::setRootSubfolder
            )
        );
    }
}