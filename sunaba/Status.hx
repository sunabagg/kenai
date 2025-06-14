package sunaba;

enum abstract Status(Int) {
	var Disconnected = 0;
	var Handshaking = 1;
	var Connected = 2;
	var Error = 3;
	var ErrorHostnameMismatch = 4;
}
