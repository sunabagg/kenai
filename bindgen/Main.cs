using Godot;
using System;

public partial class Main : Node
{

	public string apiCodePath;

	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		var bindgenPath = ProjectSettings.GlobalizePath("res://");
		var rootPath = bindgenPath + "/../";
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}

	pu
}
