package sunaba.core;

import lua.Table;

abstract StringArray(Vector<String>) from Vector<String> to Vector<String> {
    @:to
    public inline function toArray(): Array<String> {
        var table : Vector<String> = this;
        return Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<String>): StringArray {
        var result = Table.fromArray(array);
        return result;
    }
}