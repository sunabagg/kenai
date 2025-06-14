package sunaba..ui;

enum abstract ControlTextureFilter(Int) {
	var ParentNode = 0;
	var Nearest = 1;
	var Linear = 2;
	var NearestWithMipmaps = 3;
	var LinearWithMipmaps = 4;
	var NearestWithMipmapsAnisotropic = 5;
	var LinearWithMipmapsAnisotropic = 6;
	var Max = 7;
}
