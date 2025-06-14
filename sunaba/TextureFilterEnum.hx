package sunaba;

enum abstract TextureFilterEnum(Int) {
	var Default = 0;
	var Nearest = 1;
	var Linear = 2;
	var NearestMipmap = 3;
	var LinearMipmap = 4;
	var NearestMipmapAnisotropic = 5;
	var LinearMipmapAnisotropic = 6;
	var Max = 7;
}
