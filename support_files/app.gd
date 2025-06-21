extends App

var theme: Theme

# Called when the node enters the scene tree for the first time.
func _init() -> void:
	init_state(false)
	load_and_execute_sbx("res://test5/bin/test5.sbx")

func _ready() -> void:
	if (DisplayServer.is_dark_mode()):
		theme = load("res://addons/lite/dark.tres")
	else:
		theme = load("res://addons/lite/light.tres")
	get_tree().root.theme = theme
