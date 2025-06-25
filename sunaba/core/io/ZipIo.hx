package lucidware.core.io;

@:native("ZipIo")
extern class ZipIo extends IoInterface {
    public function new(path: String);
}