package lucidfx.core.io;

@:native("FileSystemIo")
extern class FileSystemIo extends SystemIoInterface {
    public var basePath: String;
    public var altPath: String;
    public var altPath2: String;
}