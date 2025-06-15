package sunaba;

enum abstract GlobalShaderParameterType(Int) from Int to Int {
	var bool = 0;
	var bvec2 = 1;
	var bvec3 = 2;
	var bvec4 = 3;
	var int = 4;
	var ivec2 = 5;
	var ivec3 = 6;
	var ivec4 = 7;
	var rect2i = 8;
	var uint = 9;
	var uvec2 = 10;
	var uvec3 = 11;
	var uvec4 = 12;
	var float = 13;
	var vec2 = 14;
	var vec3 = 15;
	var vec4 = 16;
	var color = 17;
	var rect2 = 18;
	var mat2 = 19;
	var mat3 = 20;
	var mat4 = 21;
	var transform2d = 22;
	var transform = 23;
	var sampler2d = 24;
	var sampler2Darray = 25;
	var sampler3d = 26;
	var samplercube = 27;
	var samplerext = 28;
	var max = 29;
}
