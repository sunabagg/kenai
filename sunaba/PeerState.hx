package sunaba;

enum abstract PeerState(Int) from Int to Int {
	var disconnected = 0;
	var connecting = 1;
	var acknowledgingConnect = 2;
	var connectionPending = 3;
	var connectionSucceeded = 4;
	var connected = 5;
	var disconnectLater = 6;
	var disconnecting = 7;
	var acknowledgingDisconnect = 8;
	var zombie = 9;
}
