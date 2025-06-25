package lucidware;

enum abstract DrawMode(Int) from Int to Int {
	var normal = 0;
	var pressed = 1;
	var hover = 2;
	var disabled = 3;
	var hoverPressed = 4;
}
