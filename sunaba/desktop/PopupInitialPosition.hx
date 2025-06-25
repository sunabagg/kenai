package lucidware..desktop;

enum abstract PopupInitialPosition(Int) from Int to Int {
	var absolute = 0;
	var centerPrimaryScreen = 1;
	var centerMainWindowScreen = 2;
	var centerOtherScreen = 3;
	var centerScreenWithMouseFocus = 4;
	var centerScreenWithKeyboardFocus = 5;
}
