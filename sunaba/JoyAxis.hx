package sunaba;

enum abstract JoyAxis(Int) {
	var LeftX = 0;
	var LeftY = 1;
	var RightX = 2;
	var RightY = 3;
	var TriggerLeft = 4;
	var TriggerRight = 5;
	var SdlMax = 6;
	var Max = 10;
	var Invalid = -1;
}
