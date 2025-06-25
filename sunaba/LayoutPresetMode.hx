package lucidware;

enum abstract LayoutPresetMode(Int) from Int to Int {
	var minsize = 0;
	var keepWidth = 1;
	var keepHeight = 2;
	var keepSize = 3;
}
