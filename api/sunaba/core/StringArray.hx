package sunaba.core;

import lua.Table;

abstract StringArray(Table<Int, String>) from Table<Int, String> to Table<Int, String> {
    @:to
    public inline function toArray(): Array<String> {
        var table : Table<Int, String> = this;
        return Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<String>): StringArray {
        var result = Table.fromArray(array);
        return result;
    }
}