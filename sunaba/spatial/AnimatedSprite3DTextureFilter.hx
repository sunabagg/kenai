package sunaba..spatial;

enum abstract AnimatedSprite3DTextureFilter(Int) {
	var Nearest = 0;
	var Linear = 1;
	var NearestWithMipmaps = 2;
	var LinearWithMipmaps = 3;
	var NearestWithMipmapsAnisotropic = 4;
	var LinearWithMipmapsAnisotropic = 5;
	var Max = 6;
}
