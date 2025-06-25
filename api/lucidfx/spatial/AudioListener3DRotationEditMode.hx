package lucidfx..spatial;

enum abstract AudioListener3DRotationEditMode(Int) from Int to Int {
	var euler = 0;
	var quaternion = 1;
	var basis = 2;
}
