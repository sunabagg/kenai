package lucidfx;

enum abstract ConeTwistJointParam(Int) from Int to Int {
	var swingSpan = 0;
	var twistSpan = 1;
	var bias = 2;
	var softness = 3;
	var relaxation = 4;
}
