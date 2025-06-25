package lucidfx..core;

enum abstract CanvasItemProcessThreadMessages(Int) from Int to Int {
	var messages = 1;
	var messagesPhysics = 2;
	var messagesAll = 3;
}
