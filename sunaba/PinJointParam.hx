package sunaba;

enum abstract PinJointParam(Int) from Int to Int {
	var bias = 0;
	var damping = 1;
	var impulseClamp = 2;
}
