package sunaba;

enum abstract FillModeEnum(Int) from Int to Int {
	var leftToRight = 0;
	var rightToLeft = 1;
	var topToBottom = 2;
	var bottomToTop = 3;
	var clockwise = 4;
	var counterClockwise = 5;
	var bilinearLeftAndRight = 6;
	var bilinearTopAndBottom = 7;
	var clockwiseAndCounterClockwise = 8;
}
