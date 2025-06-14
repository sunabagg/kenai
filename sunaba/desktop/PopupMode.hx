package sunaba..desktop;

enum abstract PopupMode(Int) {
	var Windowed = 0;
	var Minimized = 1;
	var Maximized = 2;
	var Fullscreen = 3;
	var ExclusiveFullscreen = 4;
}
