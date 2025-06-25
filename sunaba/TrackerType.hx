package lucidware;

enum abstract TrackerType(Int) from Int to Int {
	var head = 1;
	var controller = 2;
	var basestation = 4;
	var anchor = 8;
	var hand = 16;
	var body = 32;
	var face = 64;
	var anyKnown = 127;
	var unknown = 128;
	var any = 255;
}
