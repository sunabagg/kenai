using Godot;
using System;
using System.Collections.Generic;
using System.IO;

public partial class Main : Node
{

	public string apiCodePath;

	public string rootPath;
	public string xmlPath;

	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		var bindgenPath = ProjectSettings.GlobalizePath("res://");
		rootPath = bindgenPath + "/../";
		apiCodePath = rootPath + "sunaba/";

		xmlPath = rootPath + "xmlgdapi/";
		
		GenerateRootEnums();

		foreach (var dir in System.IO.Directory.GetDirectories(xmlPath))
		{
			foreach (var subdir in Directory.GetDirectories(dir))
			{
				GenerateEnums(subdir, dir);
			}
		}
		
		GetTree().Quit();
	}

	public void GenerateRootEnums()
	{
		if (!Directory.Exists(apiCodePath))
		{
			Directory.CreateDirectory(apiCodePath);
		}

		var godotAsm = typeof(Node).Assembly;
		var types = godotAsm.GetTypes();

		foreach (var type in types)
		{
			if (type.IsEnum)
			{
				var enumName = type.Name;
				var codeFile = apiCodePath + enumName + ".hx";
				var packageName = "sunaba";

				var stringBuilder = new System.Text.StringBuilder();
				stringBuilder.AppendLine("package " + packageName + ";");
				stringBuilder.AppendLine();
				stringBuilder.AppendLine("enum abstract " + enumName + "(Int) {");

				foreach (var value in Enum.GetValues(type))
				{
					var valName = Enum.GetName(type, value);
					var valValue = Convert.ToInt64(value);
					stringBuilder.AppendLine("	var " + valName + " = " + valValue + ";");
				}

				stringBuilder.AppendLine("}");

				//File.WriteAllText(codeFile, stringBuilder.ToString());
			}
		}
	}

	public void GenerateEnums(string xmlDir, string parentDirPath)
	{
		foreach (var subdir in Directory.GetDirectories(xmlDir))
		{
			GenerateEnums(subdir, parentDirPath);
		}
		
		var files = Directory.GetFiles(xmlDir, "*.xml");
		foreach (var file in files)
		{
			var fileName = file.GetFile().GetBaseName();
			GenerateEnumFiles(xmlDir.Replace(parentDirPath, apiCodePath), fileName);
		}
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
			var enumNames = type.GetProperties();

			foreach (var propertyInfo in enumNames)
			{
				if (IsPropertyUniqueToType(type, propertyInfo.Name))
				{
					if (propertyInfo.PropertyType.IsEnum)
					{
						var enumName = type.Name + propertyInfo.Name;
						string enumPath = apiDir;
						if (enumName.StartsWith("animation"))
						{
							enumPath += "animation/";
							enumName = enumName.Replace("animation", String.Empty);
						}
						else if (enumName.StartsWith("core"))
						{
							enumPath += "core/";
							enumName = enumName.Replace("core", String.Empty);
						}
						else if (enumName.StartsWith("input"))
						{
							enumPath += "input/";
							enumName = enumName.Replace("input", String.Empty);
						}
						else if (enumName.StartsWith("ui"))
						{
							enumPath += "ui/";
							enumName = enumName.Replace("ui", String.Empty);
						}
						else if (enumName.StartsWith("mesh"))
						{
							enumPath += "mesh/";
							enumName = enumName.Replace("mesh", String.Empty);
						}
						else if (enumName.StartsWith("xr"))
						{
							enumPath += "xr/";
							enumName = enumName.Replace("xr", String.Empty);
						}
						else if (enumName.StartsWith("physics"))
						{
							enumPath += "physics/";
							enumName = enumName.Replace("physics", String.Empty);
						}
						else if (enumName.StartsWith("spatial"))
						{
							enumPath += "spatial/";
							enumName = enumName.Replace("spatial", String.Empty);
						}
						else if (enumName.StartsWith("desktop"))
						{
							enumPath += "desktop/";
							enumName = enumName.Replace("desktop", String.Empty);
						}
						else if (enumName.StartsWith("video"))
						{
							enumPath += "video/";
							enumName = enumName.Replace("video", String.Empty);
						}
						else if (enumName.StartsWith("audio"))
						{
							enumPath += "audio/";
							enumName = enumName.Replace("audio", String.Empty);
						}
						else if (enumName.StartsWith("editor"))
						{
							enumPath += "editor/";
							enumName = enumName.Replace("editor", String.Empty);
						}

						var codeDir = apiDir.Replace(apiCodePath, "sunaba/");
						var codeFile = apiDir + enumName + ".hx";

						var packageName = codeDir.Replace("/", ".");
						
						var stringBuilder = new System.Text.StringBuilder();
						stringBuilder.AppendLine("package " + packageName + ";");
						stringBuilder.AppendLine();
						stringBuilder.AppendLine("enum abstract " + enumName + "(Int) {");
						
						List<string> valNames = new List<string>();
						foreach (var value in Enum.GetValues(propertyInfo.PropertyType))
						{
							var valName = Enum.GetName(propertyInfo.PropertyType, value);
							var valValue = Convert.ToInt64(value);
							if (!valNames.Contains(valName))
							{
								valNames.Add(valName);
								stringBuilder.AppendLine("	var " + valName + " = " + valValue + ";");
							}
						}
						
						stringBuilder.AppendLine("}");
						
						var finalCode = stringBuilder.ToString();
						//File.WriteAllText(codeFile, finalCode);
					}
				}
			}
		}
		
	}
	
	public bool IsPropertyUniqueToType(Type type, string propertyName, bool recursive = false)
	{
		Type inheritedType = type.BaseType;
		while (inheritedType != null)
		{
			type = inheritedType;
			inheritedType = type.BaseType;
			if (IsPropertyUniqueToType(type, propertyName, true))
			{
				if (recursive)
				{
					return true;
				}
				return false;
			}
			else 
			{
				var properties = type.GetProperties();
				foreach (var propertyInfo in properties)
				{
					if (propertyInfo.Name == propertyName)
					{
						return true;
					}
				}
			}
		}
        
		return false;
	}
}
