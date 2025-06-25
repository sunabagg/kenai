package lucidfx;

enum abstract ParticleFlags(Int) from Int to Int {
	var alignYToVelocity = 0;
	var rotateY = 1;
	var disableZ = 2;
	var dampingAsFriction = 3;
	var max = 4;
}
