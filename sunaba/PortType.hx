package lucidware;

enum abstract PortType(Int) from Int to Int {
	var scalar = 0;
	var scalarInt = 1;
	var scalarUint = 2;
	var vector2d = 3;
	var vector3d = 4;
	var vector4d = 5;
	var boolean = 6;
	var transform = 7;
	var sampler = 8;
	var max = 9;
}
