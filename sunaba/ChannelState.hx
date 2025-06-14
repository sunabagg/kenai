package sunaba;

enum abstract ChannelState(Int) {
	var Connecting = 0;
	var Open = 1;
	var Closing = 2;
	var Closed = 3;
}
