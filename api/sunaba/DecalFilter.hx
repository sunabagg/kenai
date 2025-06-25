package sunaba;

enum abstract DecalFilter(Int) from Int to Int {
	var nearest = 0;
	var linear = 1;
	var nearestMipmaps = 2;
	var linearMipmaps = 3;
	var nearestMipmapsAnisotropic = 4;
	var linearMipmapsAnisotropic = 5;
}
