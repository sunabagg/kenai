package lucidfx;

enum abstract RenderingDriver(Int) from Int to Int {
	var vulkan = 0;
	var opengl3 = 1;
	var d3d12 = 2;
	var metal = 3;
}
