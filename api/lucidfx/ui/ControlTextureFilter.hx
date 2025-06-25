package lucidfx..ui;

enum abstract ControlTextureFilter(Int) from Int to Int {
	var parentNode = 0;
	var nearest = 1;
	var linear = 2;
	var nearestWithMipmaps = 3;
	var linearWithMipmaps = 4;
	var nearestWithMipmapsAnisotropic = 5;
	var linearWithMipmapsAnisotropic = 6;
	var max = 7;
}
