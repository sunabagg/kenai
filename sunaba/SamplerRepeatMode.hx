package sunaba;

enum abstract SamplerRepeatMode(Int) {
	var Repeat = 0;
	var MirroredRepeat = 1;
	var ClampToEdge = 2;
	var ClampToBorder = 3;
	var MirrorClampToEdge = 4;
	var Max = 5;
}
