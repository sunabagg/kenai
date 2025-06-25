package lucidware;

enum abstract Status(Int) from Int to Int {
	var disconnected = 0;
	var handshaking = 1;
	var connected = 2;
	var error = 3;
	var errorHostnameMismatch = 4;
}
