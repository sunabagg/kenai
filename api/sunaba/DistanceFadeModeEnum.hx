package sunaba;

enum abstract DistanceFadeModeEnum(Int) from Int to Int {
	var disabled = 0;
	var pixelAlpha = 1;
	var pixelDither = 2;
	var objectDither = 3;
}
