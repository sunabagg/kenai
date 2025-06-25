package lucidware;

enum abstract UnderlineMode(Int) from Int to Int {
	var always = 0;
	var onHover = 1;
	var never = 2;
}
