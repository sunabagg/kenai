package sunaba..spatial.lighting;

enum abstract DirectionalLight3DLightBakeMode(Int) from Int to Int {
	var disabled = 0;
	var static = 1;
	var dynamic = 2;
}
