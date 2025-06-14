package sunaba;

enum abstract RenderingDriver(Int) {
	var Vulkan = 0;
	var Opengl3 = 1;
	var D3D12 = 2;
	var Metal = 3;
}
