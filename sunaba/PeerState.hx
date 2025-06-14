package sunaba;

enum abstract PeerState(Int) {
	var Disconnected = 0;
	var Connecting = 1;
	var AcknowledgingConnect = 2;
	var ConnectionPending = 3;
	var ConnectionSucceeded = 4;
	var Connected = 5;
	var DisconnectLater = 6;
	var Disconnecting = 7;
	var AcknowledgingDisconnect = 8;
	var Zombie = 9;
}
