package sunaba..desktop;

enum abstract AcceptDialogInitialPosition(Int) {
	var Absolute = 0;
	var CenterPrimaryScreen = 1;
	var CenterMainWindowScreen = 2;
	var CenterOtherScreen = 3;
	var CenterScreenWithMouseFocus = 4;
	var CenterScreenWithKeyboardFocus = 5;
}
