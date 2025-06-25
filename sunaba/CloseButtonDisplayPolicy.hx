package lucidware;

enum abstract CloseButtonDisplayPolicy(Int) from Int to Int {
	var showNever = 0;
	var showActiveOnly = 1;
	var showAlways = 2;
	var max = 3;
}
