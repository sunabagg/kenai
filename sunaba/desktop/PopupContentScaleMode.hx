package lucidware..desktop;

enum abstract PopupContentScaleMode(Int) from Int to Int {
	var disabled = 0;
	var canvasItems = 1;
	var viewport = 2;
}
