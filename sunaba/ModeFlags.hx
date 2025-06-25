package lucidware;

enum abstract ModeFlags(Int) from Int to Int {
	var read = 1;
	var write = 2;
	var readWrite = 3;
	var writeRead = 7;
}
