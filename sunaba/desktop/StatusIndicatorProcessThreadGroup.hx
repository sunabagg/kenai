package lucidware..desktop;

enum abstract StatusIndicatorProcessThreadGroup(Int) from Int to Int {
	var inherit = 0;
	var mainThread = 1;
	var subThread = 2;
}
