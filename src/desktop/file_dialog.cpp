#include "file_dialog.h"

namespace sunaba::desktop {
    void FileDialogSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("dir_selected"), &FileDialogSignalWrapper::file_selected);
        ClassDB::bind_method(D_METHOD("file_selected"), &FileDialogSignalWrapper::file_selected);
        ClassDB::bind_method(D_METHOD("filename_filter_changed"), &FileDialogSignalWrapper::filename_filter_changed);
        ClassDB::bind_method(D_METHOD("files_selected"), &FileDialogSignalWrapper::file_selected);
    }

    void FileDialogSignalWrapper::file_selected() {
        if (element != nullptr) {
            Array args;
            element->fileSelectedEvent->emit();
        }
    }
}