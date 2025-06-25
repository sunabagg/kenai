package lucidware;

enum abstract TextureSourceEnum(Int) from Int to Int {
	var none = 0;
	var screen = 1;
	var depth = 2;
	var normalRoughness = 3;
	var max = 4;
}
