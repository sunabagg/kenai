package lucidfx;

enum abstract JointParam(Int) from Int to Int {
	var bias = 0;
	var maxBias = 1;
	var maxForce = 2;
}
