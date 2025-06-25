package lucidware;

enum abstract ModeEnum(Int) from Int to Int {
	var windowed = 0;
	var minimized = 1;
	var maximized = 2;
	var fullscreen = 3;
	var exclusiveFullscreen = 4;
}
