package lucidware;

enum abstract TrackType(Int) from Int to Int {
	var value = 0;
	var position3d = 1;
	var rotation3d = 2;
	var scale3d = 3;
	var blendShape = 4;
	var method = 5;
	var bezier = 6;
	var audio = 7;
	var animation = 8;
}
