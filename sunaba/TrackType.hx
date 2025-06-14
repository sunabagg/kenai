package sunaba;

enum abstract TrackType(Int) {
	var Value = 0;
	var Position3D = 1;
	var Rotation3D = 2;
	var Scale3D = 3;
	var BlendShape = 4;
	var Method = 5;
	var Bezier = 6;
	var Audio = 7;
	var Animation = 8;
}
