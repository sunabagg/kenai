package sunaba;

enum abstract ShaderMode(Int) {
	var Spatial = 0;
	var CanvasItem = 1;
	var Particles = 2;
	var Sky = 3;
	var Fog = 4;
	var Max = 5;
}
