package sunaba;

enum abstract PathMetadataFlags(Int) from Int to Int {
	var none = 0;
	var types = 1;
	var rids = 2;
	var owners = 4;
	var all = 7;
}
