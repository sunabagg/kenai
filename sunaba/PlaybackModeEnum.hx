package sunaba;

enum abstract PlaybackModeEnum(Int) from Int to Int {
	var randomNoRepeats = 0;
	var random = 1;
	var sequential = 2;
}
