package lucidfx;

enum abstract BoneUpdateEnum(Int) from Int to Int {
	var full = 0;
	var rotationOnly = 1;
	var max = 2;
}
