package sunaba;

enum abstract TransformFlag(Int) {
	var Position = 1;
	var Rotation = 2;
	var Scale = 4;
	var All = 7;
}
