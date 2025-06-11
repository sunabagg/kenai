package sunaba.core;

import lua.Table;

abstract StringArray(Table<Int, String>) from lua.Table<Int, String> to lua.Table<Int, String> {
    @:to
    public inline function toArray(): Array<String> {
        var table : lua.Table<Int, String> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<String>): StringArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}