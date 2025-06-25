package lucidfx;

enum abstract JointTypeEnum(Int) from Int to Int {
	var none = 0;
	var pin = 1;
	var cone = 2;
	var hinge = 3;
	var slider = 4;
	var type6Dof = 5;
}
