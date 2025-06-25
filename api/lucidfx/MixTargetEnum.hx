package lucidfx;

enum abstract MixTargetEnum(Int) from Int to Int {
	var stereo = 0;
	var surround = 1;
	var center = 2;
}
