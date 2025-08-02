package sunaba.core.io;

@:native("FileSystemIo")
extern class FileSystemIo extends SystemIoInterface {
    public var basePath: String;
    public var altPath: String;
    public var altPath2: String;
    public static function create(basePath: String, pathUri: String): FileSystemIo;
}