package sunaba;

enum abstract DuplicateFlags(Int) from Int to Int {
	var signals = 1;
	var groups = 2;
	var scripts = 4;
	var useInstantiation = 8;
}
