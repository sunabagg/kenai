package sunaba;

enum abstract HandleType(Int) {
	var DisplayHandle = 0;
	var WindowHandle = 1;
	var WindowView = 2;
	var OpenglContext = 3;
	var EglDisplay = 4;
	var EglConfig = 5;
}
