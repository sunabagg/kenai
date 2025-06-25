package lucidfx;

enum abstract JointType(Int) from Int to Int {
	var pin = 0;
	var hinge = 1;
	var slider = 2;
	var coneTwist = 3;
	var type6Dof = 4;
	var max = 5;
}
