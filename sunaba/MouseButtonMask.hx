package lucidware;

enum abstract MouseButtonMask(Int) from Int to Int {
	var left = 1;
	var right = 2;
	var middle = 4;
	var mbXbutton1 = 128;
	var mbXbutton2 = 256;
}
