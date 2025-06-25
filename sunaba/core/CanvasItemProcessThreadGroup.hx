package lucidfx..core;

enum abstract CanvasItemProcessThreadGroup(Int) from Int to Int {
	var inherit = 0;
	var mainThread = 1;
	var subThread = 2;
}
