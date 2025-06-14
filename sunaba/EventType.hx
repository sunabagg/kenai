package sunaba;

enum abstract EventType(Int) {
	var None = 0;
	var Connect = 1;
	var Disconnect = 2;
	var Receive = 3;
	var Error = -1;
}
