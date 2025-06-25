package sunaba;

enum abstract SourceEnum(Int) from Int to Int {
	var texture = 0;
	var screen = 1;
	var source2dTexture = 2;
	var source2dNormal = 3;
	var depth = 4;
	var port = 5;
	var source3dNormal = 6;
	var roughness = 7;
	var max = 8;
}
