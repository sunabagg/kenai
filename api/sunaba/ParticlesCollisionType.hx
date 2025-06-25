package sunaba;

enum abstract ParticlesCollisionType(Int) from Int to Int {
	var sphereAttract = 0;
	var boxAttract = 1;
	var vectorFieldAttract = 2;
	var sphereCollide = 3;
	var boxCollide = 4;
	var sdfCollide = 5;
	var heightfieldCollide = 6;
}
