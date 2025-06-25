package lucidfx;

enum abstract ParticlesCollisionHeightfieldResolution(Int) from Int to Int {
	var resolution256 = 0;
	var resolution512 = 1;
	var resolution1024 = 2;
	var resolution2048 = 3;
	var resolution4096 = 4;
	var resolution8192 = 5;
	var max = 6;
}
