package lucidware;

enum abstract SwitchModeEnum(Int) from Int to Int {
	var immediate = 0;
	var sync = 1;
	var atEnd = 2;
}
