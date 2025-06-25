package lucidfx;

enum abstract Parameter(Int) from Int to Int {
	var initialLinearVelocity = 0;
	var angularVelocity = 1;
	var orbitVelocity = 2;
	var linearAccel = 3;
	var radialAccel = 4;
	var tangentialAccel = 5;
	var damping = 6;
	var angle = 7;
	var scale = 8;
	var hueVariation = 9;
	var animSpeed = 10;
	var animOffset = 11;
	var turbInfluenceOverLife = 12;
	var turbVelInfluence = 13;
	var turbInitDisplacement = 14;
	var radialVelocity = 15;
	var directionalVelocity = 16;
	var scaleOverVelocity = 17;
	var max = 18;
}
