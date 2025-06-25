package lucidfx;

enum abstract JoyAxis(Int) from Int to Int {
	var leftX = 0;
	var leftY = 1;
	var rightX = 2;
	var rightY = 3;
	var triggerLeft = 4;
	var triggerRight = 5;
	var sdlMax = 6;
	var max = 10;
	var invalid = -1;
}
