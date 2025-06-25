package lucidfx..spatial.navigation;

enum abstract NavigationAgent3DProcessThreadMessages(Int) from Int to Int {
	var messages = 1;
	var messagesPhysics = 2;
	var messagesAll = 3;
}
