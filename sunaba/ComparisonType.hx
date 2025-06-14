package sunaba;

enum abstract ComparisonType(Int) {
	var Scalar = 0;
	var ScalarInt = 1;
	var ScalarUint = 2;
	var Vector2D = 3;
	var Vector3D = 4;
	var Vector4D = 5;
	var Boolean = 6;
	var Transform = 7;
	var Max = 8;
}
