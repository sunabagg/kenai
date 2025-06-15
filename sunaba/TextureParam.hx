package sunaba;

enum abstract TextureParam(Int) from Int to Int {
	var albedo = 0;
	var metallic = 1;
	var roughness = 2;
	var emission = 3;
	var normal = 4;
	var rim = 5;
	var clearcoat = 6;
	var flowmap = 7;
	var ambientOcclusion = 8;
	var heightmap = 9;
	var subsurfaceScattering = 10;
	var subsurfaceTransmittance = 11;
	var backlight = 12;
	var refraction = 13;
	var detailMask = 14;
	var detailAlbedo = 15;
	var detailNormal = 16;
	var orm = 17;
	var max = 18;
}
