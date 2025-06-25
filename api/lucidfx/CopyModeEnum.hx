package lucidfx;

enum abstract CopyModeEnum(Int) from Int to Int {
	var disabled = 0;
	var rect = 1;
	var viewport = 2;
}
