package lucidfx;

enum abstract PinJointFlag(Int) from Int to Int {
	var angularLimitEnabled = 0;
	var motorEnabled = 1;
}
