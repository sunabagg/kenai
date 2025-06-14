package sunaba..spatial.joints;

enum abstract Joint3DRotationEditMode(Int) {
	var Euler = 0;
	var Quaternion = 1;
	var Basis = 2;
}
