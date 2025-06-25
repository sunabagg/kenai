extends App

var theme: Theme

# Called when the node enters the scene tree for the first time.
func _init() -> void:
	init_state(false)
	var args = OS.get_cmdline_args()
	var lfx_path = ""
	for arg in args:
		if (arg.ends_with(".lfx") and (arg.is_absolute_path() || arg.is_relative_path())):
			lfx_path = arg
	if not lfx_path.is_empty():
		load_and_execute_lfx(lfx_path)
	else:
		load_and_execute_lfx("res://test5/bin/test5.lfx")

func _ready() -> void:
	if (DisplayServer.is_dark_mode()):
		theme = load("res://addons/lite/dark.tres")
	else:
		theme = load("res://addons/lite/light.tres")
	get_tree().root.theme = theme
