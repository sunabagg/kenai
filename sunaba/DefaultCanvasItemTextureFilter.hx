package sunaba;

enum abstract DefaultCanvasItemTextureFilter(Int) {
	var Nearest = 0;
	var Linear = 1;
	var LinearWithMipmaps = 2;
	var NearestWithMipmaps = 3;
	var Max = 4;
}
