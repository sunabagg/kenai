package sunaba;

enum abstract ChannelState(Int) from Int to Int {
	var connecting = 0;
	var open = 1;
	var closing = 2;
	var closed = 3;
}
