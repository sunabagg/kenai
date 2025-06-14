package sunaba;

enum abstract ParticlesCollisionType(Int) {
	var SphereAttract = 0;
	var BoxAttract = 1;
	var VectorFieldAttract = 2;
	var SphereCollide = 3;
	var BoxCollide = 4;
	var SdfCollide = 5;
	var HeightfieldCollide = 6;
}
