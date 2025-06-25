package lucidfx..spatial;

enum abstract SpriteBase3DCastShadow(Int) from Int to Int {
	var off = 0;
	var on = 1;
	var doubleSided = 2;
	var shadowsOnly = 3;
}
