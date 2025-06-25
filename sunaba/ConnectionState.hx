package lucidware;

enum abstract ConnectionState(Int) from Int to Int {
	var new = 0;
	var connecting = 1;
	var connected = 2;
	var disconnected = 3;
	var failed = 4;
	var closed = 5;
}
