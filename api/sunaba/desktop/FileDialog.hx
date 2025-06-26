package sunaba.desktop;

import sunaba.ui.VboxContainer;
import sunaba.core.Dictionary;
import sunaba.ui.LineEdit;
import sunaba.core.StringArray;
import sunaba.core.Event;

@:native("FileDialog")
extern class FileDialog extends ConfirmationDialog {
    public var access: Int;
    public var currentDir: String;
    public var currentFile: String;
    public var currentPath: String;
    public var fileMode: Int;
    public var filenameFilter: String;
    public var filters: StringArray;
    public var modeOverridesTitle: Bool;
    public var optionCount: Int;
    public var rootSubfolder: String;
    public var showHiddenFiles: Bool;
    public var useNativeDialog: Bool;
    public var dirSelected: Event;
    public var fileSelected: Event;
    public var filenameFilterChanged: Event;
    public var filesSelected: Event;
    public function addFilter(filter: String, ?description: String): Void;
    public function addOption(name: String, values: StringArray, defaultValueIndex: Int): Void;
    public function clearFilenameFilter(): Void;
    public function clearFilters(): Void;
    public function deselectAll(): Void;
    public function getLineEdit(): LineEdit;
    public function getOptionDefault(option: Int): Int;
    public function getOptionName(option: Int): Int;
    public function getOptionValues(option: Int): Int;
    public function getSelectedOptions(): Dictionary;
    public function getVbox(): VboxContainer;
}