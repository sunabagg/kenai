package lucidfx;

enum abstract JoyButton(Int) from Int to Int {
	var a = 0;
	var b = 1;
	var x = 2;
	var y = 3;
	var back = 4;
	var guide = 5;
	var start = 6;
	var leftStick = 7;
	var rightStick = 8;
	var leftShoulder = 9;
	var rightShoulder = 10;
	var dpadUp = 11;
	var dpadDown = 12;
	var dpadLeft = 13;
	var dpadRight = 14;
	var misc1 = 15;
	var paddle1 = 16;
	var paddle2 = 17;
	var paddle3 = 18;
	var paddle4 = 19;
	var touchpad = 20;
	var sdlMax = 21;
	var max = 128;
	var invalid = -1;
}
