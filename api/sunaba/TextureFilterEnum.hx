package sunaba;

enum abstract TextureFilterEnum(Int) from Int to Int {
	var default = 0;
	var nearest = 1;
	var linear = 2;
	var nearestMipmap = 3;
	var linearMipmap = 4;
	var nearestMipmapAnisotropic = 5;
	var linearMipmapAnisotropic = 6;
	var max = 7;
}
