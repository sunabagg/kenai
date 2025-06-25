package lucidware;

enum abstract OneShotRequest(Int) from Int to Int {
	var none = 0;
	var fire = 1;
	var abort = 2;
	var fadeOut = 3;
}
