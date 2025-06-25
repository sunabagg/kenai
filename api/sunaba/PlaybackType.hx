package sunaba;

enum abstract PlaybackType(Int) from Int to Int {
	var default = 0;
	var stream = 1;
	var sample = 2;
	var max = 3;
}
