package sunaba;

enum abstract FillModeEnum(Int) {
	var LeftToRight = 0;
	var RightToLeft = 1;
	var TopToBottom = 2;
	var BottomToTop = 3;
	var Clockwise = 4;
	var CounterClockwise = 5;
	var BilinearLeftAndRight = 6;
	var BilinearTopAndBottom = 7;
	var ClockwiseAndCounterClockwise = 8;
}
