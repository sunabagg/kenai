package lucidware..ui;

enum abstract VideoStreamPlayerMouseFilter(Int) from Int to Int {
	var stop = 0;
	var pass = 1;
	var ignore = 2;
}
