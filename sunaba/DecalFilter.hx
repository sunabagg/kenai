package sunaba;

enum abstract DecalFilter(Int) {
	var Nearest = 0;
	var Linear = 1;
	var NearestMipmaps = 2;
	var LinearMipmaps = 3;
	var NearestMipmapsAnisotropic = 4;
	var LinearMipmapsAnisotropic = 5;
}
