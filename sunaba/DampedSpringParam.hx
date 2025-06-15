package sunaba;

enum abstract DampedSpringParam(Int) from Int to Int {
	var restLength = 0;
	var stiffness = 1;
	var damping = 2;
}
