package lucidware..animation;

enum abstract AnimationPlayerCallbackModeDiscrete(Int) from Int to Int {
	var dominant = 0;
	var recessive = 1;
	var forceContinuous = 2;
}
