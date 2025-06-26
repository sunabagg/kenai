#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <godot_cpp/classes/file_dialog.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define FileDialogNode godot::FileDialog

#include "confirmation_dialog.h"
#include "../ui/v_box_container.h"

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

            void dir_selected(const String& dir);
            void file_selected(const String& path);
            void filename_filter_changed(const String& filter);
            void files_selected();
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

                fileDialog->connect("dir_selected", Callable(signalWrapper, "dir_selected"));
                fileDialog->connect("file_selected", Callable(signalWrapper, "file_selected"));
                fileDialog->connect("filename_filter_changed", Callable(signalWrapper, "filename_filter_changed"));
                fileDialog->connect("files_selected", Callable(signalWrapper, "files_selected"));
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

            void setOptionCount(int value) {
                fileDialog->set_option_count(value);
            }

            std::string getRootSubfolder() {
                return fileDialog->get_root_subfolder().utf8().get_data();
            }

            void setRootSubfolder(std::string value) {
                fileDialog->set_root_subfolder(value.c_str());
            }

            bool getShowHiddenFiles() {
                return fileDialog->is_showing_hidden_files();
            }

            void setShowHiddenFiles(bool value) {
                fileDialog->set_show_hidden_files(value);
            }

            bool getUseNativeDialog() {
                return fileDialog->get_use_native_dialog();
            }

            void setUseNativeDialog(bool value) {
                fileDialog->set_use_native_dialog(value);
            }

            Event* dirSelectedEvent = new Event();
            Event* getDirSelectedEvent() {
                return dirSelectedEvent;
            }
            void setDirSelectedEvent(Event* e) {
                dirSelectedEvent = e;
            }

            Event* fileSelectedEvent = new Event();
            Event* getFileSelectedEvent() {
                return fileSelectedEvent;
            }
            void setFileSelectedEvent(Event* e) {
                fileSelectedEvent = e;
            }

            Event* filenameFilterChangedEvent = new Event();
            Event* getFilenameFilterChangedEvent() {
                return filenameFilterChangedEvent;
            }
            void setFilenameFilterChangedEvent(Event* e) {
                filenameFilterChangedEvent = e;
            }

            Event* filesSelectedEvent = new Event();
            Event* getFilesSelectedEvent() {
                return filesSelectedEvent;
            }
            void setFilesSelectedEvent(Event* e) {
                filesSelectedEvent = e;
            }

            void addFilter(std::string filter, std::string description = "") {
                fileDialog->add_filter(filter.c_str(), description.c_str());
            }

            void addOption(std::string name, std::vector<std::string> valuesVector, int defaultValueIndex) {
                PackedStringArray values;
                for (std::string value : valuesVector) {
                    values.append(value.c_str());
                }
                fileDialog->add_option(name.c_str(), values, defaultValueIndex);
            }

            void clearFilenameFilter() {
                fileDialog->clear_filename_filter();
            }

            void clearFilters() {
                fileDialog->clear_filters();
            }

            void deselectAll() {
                fileDialog->deselect_all();
            }

            sunaba::ui::LineEdit* getLineEdit() {
                return new sunaba::ui::LineEdit(fileDialog->get_line_edit());
            }

            int getOptionDefault(int option) {
                return fileDialog->get_option_default(option);
            }

            std::string getOptionName(int option) {
                return fileDialog->get_option_name(option).utf8().get_data();
            }

            std::vector<std::string> getOptionValues(int option) {
                std::vector<std::string> result;
                auto optionValues = fileDialog->get_option_values(option);
                for (size_t i = 0; i < optionValues.size(); i++)
                {
                    result.push_back(optionValues[i].utf8().get_data());
                }
                return result;
            }

            Dictionary getSelectedOptions() {
                return fileDialog->get_selected_options();
            }

            sunaba::ui::VBoxContainer* getVbox() {
                return new sunaba::ui::VBoxContainer(fileDialog->get_vbox());
            }

            void invalidate() {
                fileDialog->invalidate();
            }

            void setOptionDefault(int option, int defaultValueIndex) {
                fileDialog->set_option_default(option, defaultValueIndex);
            }

            void setOptionName(int option, std::string name) {
                fileDialog->set_option_name(option, name.c_str());
            }

            void setOptionValues(int option, std::vector<std::string> values) {
                PackedStringArray finalValues;
                for( std::string value : values ) {
                    finalValues.append(value.c_str());
                }
                fileDialog->set_option_values(option, finalValues);
            }
    };
}

#endif