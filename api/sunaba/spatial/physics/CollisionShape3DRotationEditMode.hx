package sunaba..spatial.physics;

enum abstract CollisionShape3DRotationEditMode(Int) from Int to Int {
	var euler = 0;
	var quaternion = 1;
	var basis = 2;
}
