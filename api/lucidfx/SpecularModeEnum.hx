package lucidfx;

enum abstract SpecularModeEnum(Int) from Int to Int {
	var schlickGgx = 0;
	var toon = 1;
	var disabled = 2;
}
