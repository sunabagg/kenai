package lucidfx..animation;

enum abstract AnimationTreeCallbackModeDiscrete(Int) from Int to Int {
	var dominant = 0;
	var recessive = 1;
	var forceContinuous = 2;
}
