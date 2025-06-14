package sunaba;

enum abstract VSyncMode(Int) {
	var Disabled = 0;
	var Enabled = 1;
	var Adaptive = 2;
	var Mailbox = 3;
}
