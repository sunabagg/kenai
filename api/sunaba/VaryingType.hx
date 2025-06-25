package sunaba;

enum abstract VaryingType(Int) from Int to Int {
	var float = 0;
	var int = 1;
	var uint = 2;
	var vector2d = 3;
	var vector3d = 4;
	var vector4d = 5;
	var boolean = 6;
	var transform = 7;
	var max = 8;
}
