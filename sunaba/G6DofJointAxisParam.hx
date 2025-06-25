package lucidware;

enum abstract G6DofJointAxisParam(Int) from Int to Int {
	var linearLowerLimit = 0;
	var linearUpperLimit = 1;
	var linearLimitSoftness = 2;
	var linearRestitution = 3;
	var linearDamping = 4;
	var linearMotorTargetVelocity = 5;
	var linearMotorForceLimit = 6;
	var linearSpringStiffness = 7;
	var linearSpringDamping = 8;
	var linearSpringEquilibriumPoint = 9;
	var angularLowerLimit = 10;
	var angularUpperLimit = 11;
	var angularLimitSoftness = 12;
	var angularDamping = 13;
	var angularRestitution = 14;
	var angularForceLimit = 15;
	var angularErp = 16;
	var angularMotorTargetVelocity = 17;
	var angularMotorForceLimit = 18;
	var angularSpringStiffness = 19;
	var angularSpringDamping = 20;
	var angularSpringEquilibriumPoint = 21;
	var max = 22;
}
