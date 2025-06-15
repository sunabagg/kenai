package sunaba..core;

enum abstract WorldEnvironmentProcessThreadGroup(Int) from Int to Int {
	var inherit = 0;
	var mainThread = 1;
	var subThread = 2;
}
