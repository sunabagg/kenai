package sunaba..spatial.physics;

enum abstract CollisionObject3DRotationEditMode(Int) from Int to Int {
	var euler = 0;
	var quaternion = 1;
	var basis = 2;
}
