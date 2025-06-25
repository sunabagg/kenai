package lucidware;

enum abstract SamplerRepeatMode(Int) from Int to Int {
	var repeat = 0;
	var mirroredRepeat = 1;
	var clampToEdge = 2;
	var clampToBorder = 3;
	var mirrorClampToEdge = 4;
	var max = 5;
}
