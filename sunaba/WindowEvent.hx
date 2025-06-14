package sunaba;

enum abstract WindowEvent(Int) {
	var MouseEnter = 0;
	var MouseExit = 1;
	var FocusIn = 2;
	var FocusOut = 3;
	var CloseRequest = 4;
	var GoBackRequest = 5;
	var DpiChange = 6;
	var TitlebarChange = 7;
}
