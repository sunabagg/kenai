package lucidfx..audio;

enum abstract AudioStreamPlayerProcessThreadGroup(Int) from Int to Int {
	var inherit = 0;
	var mainThread = 1;
	var subThread = 2;
}
