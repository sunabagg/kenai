package sunaba;

enum abstract State(Int) {
	var Connecting = 0;
	var Open = 1;
	var Closing = 2;
	var Closed = 3;
}
