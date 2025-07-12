#include "file_dialog.h"

namespace kenai::desktop {
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
            sol::base_classes, sol::bases<BaseObject, Element, kenai::core::Viewport, Window, AcceptDialog, ConfirmationDialog>(),
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
            ),
            "showHiddenFiles", sol::property(
                &FileDialog::getShowHiddenFiles,
                &FileDialog::setShowHiddenFiles
            ),

            "useNativeDialog", sol::property(
                &FileDialog::getUseNativeDialog,
                &FileDialog::setUseNativeDialog
            ),
            "dirSelected", sol::property(
                &FileDialog::getDirSelectedEvent,
                &FileDialog::setDirSelectedEvent
            ),
            "fileSelected", sol::property(
                &FileDialog::getFileSelectedEvent,
                &FileDialog::setFileSelectedEvent
            ),
            "filenameFilterChanged", sol::property(
                &FileDialog::getFilenameFilterChangedEvent,
                &FileDialog::setFilenameFilterChangedEvent
            ),
            "filesSelected", sol::property(
                &FileDialog::getFilesSelectedEvent,
                &FileDialog::setFilesSelectedEvent
            ),
            "addFilter", sol::factories(
                [](FileDialog* fdialog, std::string filter) {
                    fdialog->addFilter(filter);
                },
                [](FileDialog* fdialog, std::string filter, std::string description) {
                    fdialog->addFilter(filter, description);
                }
            ),
            "addOptions", &FileDialog::addOption,
            "clearFilenameFilter", &FileDialog::clearFilenameFilter,
            "clearFilters", &FileDialog::clearFilters,
            "deselectAll", &FileDialog::deselectAll,
            "getLineEdit", &FileDialog::getLineEdit,
            "getOptionDefault", &FileDialog::getOptionDefault,
            "getOptionName", &FileDialog::getOptionName,
            "getOptionValues", &FileDialog::getOptionValues,
            "getSelectedOptions", &FileDialog::getSelectedOptions,
            "getVbox", &FileDialog::getVbox,
            "invalidate", &FileDialog::invalidate,
            "setOptionDefault", &FileDialog::setOptionDefault,
            "setOptionName", &FileDialog::setOptionName,
            "setOptionValues", &FileDialog::setOptionValues,
            "cast", [](Element* e) {
                auto* ce = dynamic_cast<FileDialog*>(e);
                if (ce != nullptr) {
                    return ce;
                }
                FileDialogNode* fileDialog = Object::cast_to<FileDialogNode>(e->getNode());
                return new FileDialog(fileDialog);
            }
        );
    }
}