package sunaba;

enum abstract ModeFlags(Int) {
	var Read = 1;
	var Write = 2;
	var ReadWrite = 3;
	var WriteRead = 7;
}
