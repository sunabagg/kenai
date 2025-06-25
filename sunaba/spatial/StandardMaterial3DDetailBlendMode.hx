package lucidfx..spatial;

enum abstract StandardMaterial3DDetailBlendMode(Int) from Int to Int {
	var mix = 0;
	var add = 1;
	var sub = 2;
	var mul = 3;
	var premultAlpha = 4;
}
