package sunaba.desktop;

@:native("FileDialog")
extern class FileDialog extends ConfirmationDialog {
    public var access: Int;
    public var currentDir: String;
    public var currentFile: String;
}