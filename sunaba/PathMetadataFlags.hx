package sunaba;

enum abstract PathMetadataFlags(Int) {
	var None = 0;
	var Types = 1;
	var Rids = 2;
	var Owners = 4;
	var All = 7;
}
