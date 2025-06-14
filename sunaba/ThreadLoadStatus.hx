package sunaba;

enum abstract ThreadLoadStatus(Int) {
	var InvalidResource = 0;
	var InProgress = 1;
	var Failed = 2;
	var Loaded = 3;
}
