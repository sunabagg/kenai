package lucidfx..animation;

enum abstract AnimationPlayerCallbackModeProcess(Int) from Int to Int {
	var physics = 0;
	var idle = 1;
	var manual = 2;
}
