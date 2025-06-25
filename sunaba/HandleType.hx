package lucidware;

enum abstract HandleType(Int) from Int to Int {
	var displayHandle = 0;
	var windowHandle = 1;
	var windowView = 2;
	var openglContext = 3;
	var eglDisplay = 4;
	var eglConfig = 5;
}
