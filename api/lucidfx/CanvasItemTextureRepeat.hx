package lucidfx;

enum abstract CanvasItemTextureRepeat(Int) from Int to Int {
	var default = 0;
	var disabled = 1;
	var enabled = 2;
	var mirror = 3;
	var max = 4;
}
