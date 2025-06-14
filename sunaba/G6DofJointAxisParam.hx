package sunaba;

enum abstract G6DofJointAxisParam(Int) {
	var LinearLowerLimit = 0;
	var LinearUpperLimit = 1;
	var LinearLimitSoftness = 2;
	var LinearRestitution = 3;
	var LinearDamping = 4;
	var LinearMotorTargetVelocity = 5;
	var LinearMotorForceLimit = 6;
	var LinearSpringStiffness = 7;
	var LinearSpringDamping = 8;
	var LinearSpringEquilibriumPoint = 9;
	var AngularLowerLimit = 10;
	var AngularUpperLimit = 11;
	var AngularLimitSoftness = 12;
	var AngularDamping = 13;
	var AngularRestitution = 14;
	var AngularForceLimit = 15;
	var AngularErp = 16;
	var AngularMotorTargetVelocity = 17;
	var AngularMotorForceLimit = 18;
	var AngularSpringStiffness = 19;
	var AngularSpringDamping = 20;
	var AngularSpringEquilibriumPoint = 21;
	var Max = 22;
}
