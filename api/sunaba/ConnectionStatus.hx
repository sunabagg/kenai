package sunaba;

enum abstract ConnectionStatus(Int) from Int to Int {
	var disconnected = 0;
	var connecting = 1;
	var connected = 2;
}
