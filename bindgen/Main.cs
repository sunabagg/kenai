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
		apiCodePath = rootPath + "sunaba/";

		var xmlPath = apiCodePath + "xmlgdapi/";

		foreach (var dir in System.IO.Directory.GetDirectories(xmlPath))
		{
			GenerateEnums(dir);
		}
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}

	public void GenerateEnums(string apiDir)
	{

	}

	public void GenerateEnumFiles(string apiDir, string className)
	{
		var godotAsm = typeof(Node).Assembly;
		var types = godotAsm.GetTypes();

		Type type = null;

		foreach (var t in types)
		{
			if (t.Name == className)
			{
				type = t;
				break;
			}
		}

		if (type != null)
		{
			var enumName = type.GetProperties();
		}
		
	}
}
