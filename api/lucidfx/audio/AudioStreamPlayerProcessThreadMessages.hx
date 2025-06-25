package lucidfx..audio;

enum abstract AudioStreamPlayerProcessThreadMessages(Int) from Int to Int {
	var messages = 1;
	var messagesPhysics = 2;
	var messagesAll = 3;
}
