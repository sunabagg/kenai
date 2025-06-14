package sunaba;

enum abstract GlobalShaderParameterType(Int) {
	var Bool = 0;
	var Bvec2 = 1;
	var Bvec3 = 2;
	var Bvec4 = 3;
	var Int = 4;
	var Ivec2 = 5;
	var Ivec3 = 6;
	var Ivec4 = 7;
	var Rect2I = 8;
	var Uint = 9;
	var Uvec2 = 10;
	var Uvec3 = 11;
	var Uvec4 = 12;
	var Float = 13;
	var Vec2 = 14;
	var Vec3 = 15;
	var Vec4 = 16;
	var Color = 17;
	var Rect2 = 18;
	var Mat2 = 19;
	var Mat3 = 20;
	var Mat4 = 21;
	var Transform2D = 22;
	var Transform = 23;
	var Sampler2D = 24;
	var Sampler2Darray = 25;
	var Sampler3D = 26;
	var Samplercube = 27;
	var Samplerext = 28;
	var Max = 29;
}
