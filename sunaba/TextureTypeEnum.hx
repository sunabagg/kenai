package lucidware;

enum abstract TextureTypeEnum(Int) from Int to Int {
	var data = 0;
	var color = 1;
	var normalMap = 2;
	var anisotropy = 3;
	var max = 4;
}
