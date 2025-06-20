extends App


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	get_window().theme = load("res://addons/lite/light.tres")
	start("res://test5")
