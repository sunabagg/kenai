package lucidware;

enum abstract CanvasItemTextureFilter(Int) from Int to Int {
	var default = 0;
	var nearest = 1;
	var linear = 2;
	var nearestWithMipmaps = 3;
	var linearWithMipmaps = 4;
	var nearestWithMipmapsAnisotropic = 5;
	var linearWithMipmapsAnisotropic = 6;
	var max = 7;
}
