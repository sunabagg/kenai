package lucidfx;

enum abstract UniformType(Int) from Int to Int {
	var sampler = 0;
	var samplerWithTexture = 1;
	var texture = 2;
	var image = 3;
	var textureBuffer = 4;
	var samplerWithTextureBuffer = 5;
	var imageBuffer = 6;
	var uniformBuffer = 7;
	var storageBuffer = 8;
	var inputAttachment = 9;
	var max = 10;
}
