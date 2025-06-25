package lucidware;

enum abstract GltfAccessorType(Int) from Int to Int {
	var scalar = 0;
	var vec2 = 1;
	var vec3 = 2;
	var vec4 = 3;
	var mat2 = 4;
	var mat3 = 5;
	var mat4 = 6;
}
