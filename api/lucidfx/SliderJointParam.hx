package lucidfx;

enum abstract SliderJointParam(Int) from Int to Int {
	var linearLimitUpper = 0;
	var linearLimitLower = 1;
	var linearLimitSoftness = 2;
	var linearLimitRestitution = 3;
	var linearLimitDamping = 4;
	var linearMotionSoftness = 5;
	var linearMotionRestitution = 6;
	var linearMotionDamping = 7;
	var linearOrthogonalSoftness = 8;
	var linearOrthogonalRestitution = 9;
	var linearOrthogonalDamping = 10;
	var angularLimitUpper = 11;
	var angularLimitLower = 12;
	var angularLimitSoftness = 13;
	var angularLimitRestitution = 14;
	var angularLimitDamping = 15;
	var angularMotionSoftness = 16;
	var angularMotionRestitution = 17;
	var angularMotionDamping = 18;
	var angularOrthogonalSoftness = 19;
	var angularOrthogonalRestitution = 20;
	var angularOrthogonalDamping = 21;
	var max = 22;
}
