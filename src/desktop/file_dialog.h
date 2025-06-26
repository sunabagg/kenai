#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <godot_cpp/classes/file_dialog.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define FileDialogNode godot::FileDialog

#include "confirmation_dialog.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindFileDialog(sol::state& lua);

    class FileDialog;

    class FileDialogSignalWrapper : public Object {
        GDCLASS(FileDialogSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            FileDialog* element = nullptr;

            FileDialogSignalWrapper() = default;
            ~FileDialogSignalWrapper() = default;
    };

    class FileDialog : public ConfirmationDialog {
        private:
            FileDialogNode* fileDialog = nullptr;
            FileDialogSignalWrapper* signalWrapper = nullptr;

            void connectFileDialogSignals() {
                if (signalWrapper == nullptr) {
                    signalWrapper = memnew(FileDialogSignalWrapper);
                    signalWrapper->element = this;
                }
            }

        public:
            FileDialog() {
                setFileDialog(memnew(FileDialogNode));
                onInit();
            }

            FileDialog(FileDialogNode* node) {
                setFileDialog(node);
            }

            FileDialogNode* getFileDialog() {
                return fileDialog;
            }

            void setFileDialog(FileDialogNode* node) {
                fileDialog = node;
                connectFileDialogSignals();
                setConfirmationDialog(fileDialog);
            }

            int getAccess() {
                return fileDialog->get_access();
            }

            void setAccess(int value) {
                fileDialog->set_access(static_cast<FileDialogNode::Access>(value));
            }

            std::string getCurrentDir() {
                return fileDialog->get_current_dir().utf8().get_data();
            }

            void setCurrentDir(std::string value) {
                return fileDialog->set_current_dir(value.c_str());
            }

            std::string getCurrentFile() {
                return fileDialog->get_current_file().utf8().get_data();
            }

            void setCurrentFile(std::string value) {
                fileDialog->set_current_file(value.c_str());
            }

            std::string getCurrentPath() {
                return fileDialog->get_current_path().utf8().get_data();
            }

            void setCurrentPath(std::string value) {
                fileDialog->set_current_path(value.c_str());
            }

            int getFileMode() {
                return fileDialog->get_file_mode();
            }
            
            void setFileMode(int value) {
                fileDialog->set_file_mode(static_cast<FileDialogNode::FileMode>(value));
            }

            std::string getFilenameFilter() {
                return fileDialog->get_filename_filter().utf8().get_data();
            }

            void setFilenameFilter(std::string value) {
                fileDialog->set_filename_filter(value.c_str());
            }

            std::vector<std::string> getFilters() {
                std::vector<std::string> filters;
                PackedStringArray filtersPsa = fileDialog->get_filters();
                for (size_t i = 0; i < filtersPsa.size(); i++)
                {
                    filters.push_back(filtersPsa[i].utf8().get_data());
                }
                return filters;
            }

            void setFilters(std::vector<std::string> value) {
                PackedStringArray filters;
                for (std::string filter : value)
                {
                    filters.append(filter.c_str());
                }
                fileDialog->set_filters(filters);
            }

            bool getModeOverridesTitle() {
                return fileDialog->is_mode_overriding_title();
            }

            void setModeOverridesTitle(bool value) {
                fileDialog->set_mode_overrides_title(value);
            }

            int getOptionCount() {
                return fileDialog->get_option_count();
            }
    };
}

#endif