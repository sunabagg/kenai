package sunaba;

enum abstract ReplicationMode(Int) {
	var Never = 0;
	var Always = 1;
	var OnChange = 2;
}
