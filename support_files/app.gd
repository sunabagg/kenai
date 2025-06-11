extends App


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	get_window().theme = load("res://addons/lite/light.tres")
	start("res://test4")


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass
