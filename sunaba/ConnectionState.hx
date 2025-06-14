package sunaba;

enum abstract ConnectionState(Int) {
	var New = 0;
	var Connecting = 1;
	var Connected = 2;
	var Disconnected = 3;
	var Failed = 4;
	var Closed = 5;
}
