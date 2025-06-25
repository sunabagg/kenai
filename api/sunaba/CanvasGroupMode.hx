package sunaba;

enum abstract CanvasGroupMode(Int) from Int to Int {
	var disabled = 0;
	var clipOnly = 1;
	var clipAndDraw = 2;
	var transparent = 3;
}
