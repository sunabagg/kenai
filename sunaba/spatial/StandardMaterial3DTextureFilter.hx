package lucidware..spatial;

enum abstract StandardMaterial3DTextureFilter(Int) from Int to Int {
	var nearest = 0;
	var linear = 1;
	var nearestWithMipmaps = 2;
	var linearWithMipmaps = 3;
	var nearestWithMipmapsAnisotropic = 4;
	var linearWithMipmapsAnisotropic = 5;
	var max = 6;
}
