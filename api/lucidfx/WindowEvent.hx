package lucidfx;

enum abstract WindowEvent(Int) from Int to Int {
	var mouseEnter = 0;
	var mouseExit = 1;
	var focusIn = 2;
	var focusOut = 3;
	var closeRequest = 4;
	var goBackRequest = 5;
	var dpiChange = 6;
	var titlebarChange = 7;
}
