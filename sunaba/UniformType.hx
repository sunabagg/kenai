package sunaba;

enum abstract UniformType(Int) {
	var Sampler = 0;
	var SamplerWithTexture = 1;
	var Texture = 2;
	var Image = 3;
	var TextureBuffer = 4;
	var SamplerWithTextureBuffer = 5;
	var ImageBuffer = 6;
	var UniformBuffer = 7;
	var StorageBuffer = 8;
	var InputAttachment = 9;
	var Max = 10;
}
