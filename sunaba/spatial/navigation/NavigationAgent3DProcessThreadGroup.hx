package lucidfx..spatial.navigation;

enum abstract NavigationAgent3DProcessThreadGroup(Int) from Int to Int {
	var inherit = 0;
	var mainThread = 1;
	var subThread = 2;
}
