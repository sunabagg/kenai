package lucidware..spatial;

enum abstract StandardMaterial3DSpecularMode(Int) from Int to Int {
	var schlickGgx = 0;
	var toon = 1;
	var disabled = 2;
}
