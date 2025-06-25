package lucidware;

enum abstract TextureSliceType(Int) from Int to Int {
	var slice2d = 0;
	var cubemap = 1;
	var slice3d = 2;
}
