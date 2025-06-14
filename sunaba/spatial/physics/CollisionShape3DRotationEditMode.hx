package sunaba..spatial.physics;

enum abstract CollisionShape3DRotationEditMode(Int) {
	var Euler = 0;
	var Quaternion = 1;
	var Basis = 2;
}
