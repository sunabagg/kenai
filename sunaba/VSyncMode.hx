package sunaba;

enum abstract VSyncMode(Int) from Int to Int {
	var disabled = 0;
	var enabled = 1;
	var adaptive = 2;
	var mailbox = 3;
}
