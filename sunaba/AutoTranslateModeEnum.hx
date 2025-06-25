package lucidware;

enum abstract AutoTranslateModeEnum(Int) from Int to Int {
	var inherit = 0;
	var always = 1;
	var disabled = 2;
}
