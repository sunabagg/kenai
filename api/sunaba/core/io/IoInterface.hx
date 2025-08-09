package sunaba.core.io;

import sunaba.core.BaseObject;
import sunaba.core.Variant;

@:native("IoInterface")
extern class IoInterface extends BaseObject {
    public var pathUri: String;
    public function getFilePath(path: String): String;
    public function loadText(path: String): String;
    public function saveText(path: String, text: String): Void;
    public function loadBinary(path: String): BinaryData;
    public function saveBinary(path: String, data: BinaryData): Void;
    public function loadVariant(path: String): Variant;
    public function saveVariant(path: String, data: Variant): Void;
    public function getFileListAll(?extension: String, ?recursive: Bool): StringArray;
    public function getFileList(path: String, ?extension: String, ?recursive: Bool): StringArray;
    public function fileExists(path: String): Bool;
    public function deleteFile(path: String): Void;
    public function moveFile(src: String, dest: String): Void;
    public function createDirectory(path: String): Void;
    public function deleteDirectory(path: String): Void;
    public function directoryExists(path: String): Bool;
}