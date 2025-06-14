package sunaba;

enum abstract Type(Int) {
	var Vertex = 0;
	var Fragment = 1;
	var Light = 2;
	var Start = 3;
	var Process = 4;
	var Collide = 5;
	var StartCustom = 6;
	var ProcessCustom = 7;
	var Sky = 8;
	var Fog = 9;
	var Max = 10;
}
