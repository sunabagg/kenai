package sunaba.desktop;

import sunaba.core.StringArray;

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
}