package lucidfx;

enum abstract DefaultCanvasItemTextureFilter(Int) from Int to Int {
	var nearest = 0;
	var linear = 1;
	var linearWithMipmaps = 2;
	var nearestWithMipmaps = 3;
	var max = 4;
}
