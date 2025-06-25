package lucidware;

enum abstract ClearMode(Int) from Int to Int {
	var always = 0;
	var never = 1;
	var once = 2;
}
