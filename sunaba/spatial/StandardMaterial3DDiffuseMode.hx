package lucidware..spatial;

enum abstract StandardMaterial3DDiffuseMode(Int) from Int to Int {
	var burley = 0;
	var lambert = 1;
	var lambertWrap = 2;
	var toon = 3;
}
