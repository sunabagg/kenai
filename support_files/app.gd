extends App


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	get_window().theme = load("res://addons/lite/light.tres")
	init(false)
	load_and_execute_sbx("res://test5/bin/test5.sbx")
