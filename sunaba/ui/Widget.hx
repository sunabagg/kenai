package sunaba.ui;

import sunaba.core.FontFile;
import sunaba.core.Texture;
import sunaba.core.Image;
import sunaba.core.ImageTexture;
import sunaba.core.Texture2D;
import sunaba.core.Color;
import sunaba.core.Vector2i;
import sunaba.core.Vector4;
import sunaba.core.Vector3;
import sunaba.core.Vector2;
import sunaba.core.Vector4i;
import sunaba.core.Vector3i;
import sunaba.core.Element;
import sunaba.ui.Control;
import sunaba.core.Variant;
import sunaba.core.FontFile;
import lua.Table;
import sunaba.core.io.IoManager;
import sunaba.LayoutPreset;
import sunaba.LayoutPresetMode;
import Type;

class Widget {
    public var rootElement: Control;
    public var io: IoManager;
    public var keepChildren: Bool = false;

    public function new() {
        io = untyped __lua__("_G.ioManager");
        rootElement = new Control();

        init();
    }

    public function init() {
        
    }

    public function load(path: String): Void {
        var file = io.loadText(path);
        if (file != null && file.length > 0) {
            parseMarkup(file);
        }
        else {
            throw "Failed to load file: " + path;
        }
    }

    public function parseMarkup(markup: String): Void {
        var xml = Xml.parse(markup);
        instantiate(xml);
    }

    private function instantiate(xml: Xml): Void {
        if (rootElement != null && !keepChildren) {
            var childrenTable : Table<Int, Element> = rootElement.getChildren();
            var children : Array<Element> = Table.toArray(childrenTable);
            for (i in 0... children.length) {
                var child = children[i];
                if (child != null) {
                    child.delete();
                }
            }
        }

        var firstElement = xml.firstElement();
        if (firstElement != null) {
            if (firstElement.nodeName == "suml") {
                var fullScreenAtt = firstElement.get("fullscreen");
                if (fullScreenAtt == "true") {
                    rootElement.setAnchorsAndOffsetsPreset(cast LayoutPreset.FullRect, cast LayoutPresetMode.KeepSize);
                    rootElement.sizeFlagsHorizontal = cast SizeFlags.Fill;
                    rootElement.sizeFlagsVertical = cast SizeFlags.Fill;
                }
                else {
                    var anchorTopAtt = firstElement.get("anchorTop");
                    if (anchorTopAtt != null) {
                        rootElement.anchorTop = Std.parseFloat(anchorTopAtt);
                    }
                    var anchorLeftAtt = firstElement.get("anchorLeft");
                    if (anchorLeftAtt != null) {
                        rootElement.anchorLeft = Std.parseFloat(anchorLeftAtt);
                    }
                    var anchorBottomAtt = firstElement.get("anchorBottom");
                    if (anchorBottomAtt != null) {
                        rootElement.anchorBottom = Std.parseFloat(anchorBottomAtt);
                    }
                    var anchorRightAtt = firstElement.get("anchorRight");
                    if (anchorRightAtt != null) {
                        rootElement.anchorRight = Std.parseFloat(anchorRightAtt);
                    }

                    var offsetTopAtt = firstElement.get("offsetTop");
                    if (offsetTopAtt != null) {
                        rootElement.offsetTop = Std.parseFloat(offsetTopAtt);
                    }
                    var offsetLeftAtt = firstElement.get("offsetLeft");
                    if (offsetLeftAtt != null) {
                        rootElement.offsetLeft = Std.parseFloat(offsetLeftAtt);
                    }
                    var offsetBottomAtt = firstElement.get("offsetBottom");
                    if (offsetBottomAtt != null) {
                        rootElement.offsetBottom = Std.parseFloat(offsetBottomAtt);
                    }
                    var offsetRightAtt = firstElement.get("offsetRight");
                    if (offsetRightAtt != null) {
                        rootElement.offsetRight = Std.parseFloat(offsetRightAtt);
                    }
                }

                var nameAtt = firstElement.get("name");
                if (nameAtt != null) {
                    rootElement.name = nameAtt;
                }

                var children = firstElement.elements();
                for (child in children) {
                    if (child.nodeName == "head") {
                        for (headChild in child.elements()) {
                            if (headChild.nodeName == "style") {
                                // TODO: Implement style parsing
                            }
                        }
                    }
                    else if (child.nodeName == "body") {
                        constructNodes(child.elements());
                    }
                }

            }
            else {
                throw "Invalid root element: " + firstElement.nodeName;
            }
        }
    }

    private function constructNodes(nodes: Iterator<Xml>): Void {
        for (node in nodes) {
            var element = construct(node);
            if (element != null) {
                rootElement.addChild(element);
            }
            else {
                throw "Unknown element: " + node.nodeName;
            }
        }
    }

    private function construct(xml: Xml) : Element {
        var className = xml.nodeName;
        var classType = Type.resolveClass(className);
        if (classType != null) {
            if (isAnElementClass(classType)) {
                var instance = Type.createInstance(classType, []);
                if (instance != null) {
                    var element : Element = cast instance;
                    setObjectValues(element, xml);
                    constructChildren(element, xml);
                    if (element.name == null) {
                        var nameAtt = xml.get("name");
                        if (nameAtt != null) {
                            element.name = nameAtt;
                        }
                    }
                    return element;
                }
            }
        }
        

        throw "Unknown element class: " + className;
        return null;
    }

    private function setObjectValues(element: Element, xml: Xml): Void {
        var attributes = xml.attributes();
        for (attribute in attributes) {
            var attributeName = attribute;
            var attributeValue = xml.get(attributeName);
            if (attributeName == "name") {
                element.name = attributeValue;
            }
            else {
                if (Reflect.hasField(element, attributeName)) {
                    var currentValue = Reflect.field(element, attributeName);
                    if (Std.isOfType(currentValue, Bool)) {
                        var b : Bool = false;
                        if (attributeValue == "true") {
                            b = true;
                        }
                        else if (attributeValue == "false") {
                            b = false;
                        }
                        else {
                            throw "Invalid boolean value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                        Reflect.setProperty(element, attributeName, b);
                    }
                    else if (Std.isOfType(currentValue, Int)) {
                        var attrArr = attributeValue.split(".");
                        var value = attrArr[attrArr.length - 1];
                        attrArr.resize(attrArr.length - 1);
                        var enumName = attrArr.join(".");
                        if (enumName != "") {
                            var enum_ = Type.resolveEnum(enumName);
                            if (enum_ != null) {
                                var enumValue : Int = cast Reflect.field(enum_, value);
                                if (enumValue != null) {
                                    Reflect.setProperty(element, attributeName, enumValue);
                                }
                                else {
                                    throw "Invalid enum value '" + value + "' for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                                }
                            }
                            else {
                                throw "Unknown enum: " + enumName;
                            }
                        }
                        else  {
                            Reflect.setProperty(element, attributeName, Std.parseInt(attributeValue));
                        }
                    }
                    else if (Std.isOfType(currentValue, Float)) {
                        Reflect.setProperty(element, attributeName, Std.parseFloat(attributeValue));
                    }
                    else if (Std.isOfType(currentValue, String)) {
                        Reflect.setProperty(element, attributeName, attributeValue);
                    }
                    else if (Std.isOfType(currentValue, Vector2)) {
                        var xy = attributeValue.split(",");
                        if (xy.length == 2) {
                            var x = Std.parseFloat(xy[0]);
                            var y = Std.parseFloat(xy[1]);
                            Reflect.setProperty(element, attributeName, new Vector2(x, y));
                        }
                        else {
                            throw "Invalid Vector2 value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Vector3)) {
                        var xyz = attributeValue.split(",");
                        if (xyz.length == 3) {
                            var x = Std.parseFloat(xyz[0]);
                            var y = Std.parseFloat(xyz[1]);
                            var z = Std.parseFloat(xyz[2]);
                            Reflect.setProperty(element, attributeName, new Vector3(x, y, z));
                        }
                        else {
                            throw "Invalid Vector3 value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Vector4)) {
                        var xyzw = attributeValue.split(",");
                        if (xyzw.length == 4) {
                            var x = Std.parseFloat(xyzw[0]);
                            var y = Std.parseFloat(xyzw[1]);
                            var z = Std.parseFloat(xyzw[2]);
                            var w = Std.parseFloat(xyzw[3]);
                            Reflect.setProperty(element, attributeName, new Vector4(x, y, z, w));
                        }
                        else {
                            throw "Invalid Vector4 value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Vector2i)) {
                        var xy = attributeValue.split(",");
                        if (xy.length == 2) {
                            var x = Std.parseInt(xy[0]);
                            var y = Std.parseInt(xy[1]);
                            Reflect.setProperty(element, attributeName, new Vector2i(x, y));
                        }
                        else {
                            throw "Invalid Vector2i value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Vector3i)) {
                        var xyz = attributeValue.split(",");
                        if (xyz.length == 3) {
                            var x = Std.parseInt(xyz[0]);
                            var y = Std.parseInt(xyz[1]);
                            var z = Std.parseInt(xyz[2]);
                            Reflect.setProperty(element, attributeName, new Vector3i(x, y, z));
                        }
                        else {
                            throw "Invalid Vector3i value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Vector4i)) {
                        var xyzw = attributeValue.split(",");
                        if (xyzw.length == 4) {
                            var x = Std.parseInt(xyzw[0]);
                            var y = Std.parseInt(xyzw[1]);
                            var z = Std.parseInt(xyzw[2]);
                            var w = Std.parseInt(xyzw[3]);
                            Reflect.setProperty(element, attributeName, new Vector4i(x, y, z, w));
                        }
                        else {
                            throw "Invalid Vector4i value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Color)) {
                        var color = Color.html(attributeValue);
                        if (color != null) {
                            Reflect.setProperty(element, attributeName, color);
                        }
                        else {
                            throw "Invalid Color value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Texture2D)) {
                        var image = Image.loadFromFile(attributeValue);
                        if (image != null) {
                            var texture = ImageTexture.createFromImage(image);
                            if (texture != null) {
                                Reflect.setProperty(element, attributeName, texture);
                            }
                            else {
                                throw "Failed to create Texture2D from image for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                            }
                        }
                        else {
                            throw "Failed to load image from file for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Texture)) {
                        var image = Image.loadFromFile(attributeValue);
                        if (image != null) {
                            var texture = ImageTexture.createFromImage(image);
                            if (texture != null) {
                                Reflect.setProperty(element, attributeName, texture);
                            }
                            else {
                                throw "Failed to create Texture2D from image for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                            }
                        }
                        else {
                            throw "Failed to load image from file for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else {
                        throw "Unsupported type for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                    }
                }
                else {
                    if (Std.isOfType(element, Control)) {
                        var control: Control = cast element;
                        var snakeCaseName = camelToSnake(attributeName);
                        if (control.hasThemeConstantOverride(snakeCaseName)) {
                            control.addThemeConstantOverride(snakeCaseName, Variant.fromInt64(Std.parseInt(attributeValue)));
                            continue;
                        }
                        else if (control.hasThemeFontSizeOverride(snakeCaseName)) {
                            control.addThemeFontSizeOverride(snakeCaseName, Std.parseFloat(attributeValue));
                            continue;
                        }
                        else if (control.hasThemeColorOverride(snakeCaseName)) {
                            var color = Color.html(attributeValue);
                            if (color != null) {
                                control.addThemeColorOverride(snakeCaseName, color);
                                continue;
                            }
                            else {
                                throw "Invalid Color value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                            }
                        }
                        else if (control.hasThemeFontOverride(snakeCaseName)) {
                            var fontFile = new FontFile();
                            var res = fontFile.loadDynamicFont(attributeValue);
                            if (res != 0) {
                                res = fontFile.loadBitmapFont(attributeValue);
                                if (res != 0) {
                                    throw "Failed to load Font for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                                }
                            }
                            control.addThemeFontOverride(snakeCaseName, fontFile);
                            continue;
                        }
                        else if (control.hasThemeIconOverride(snakeCaseName)) {
                            var image = Image.loadFromFile(attributeValue);
                            if (image != null) {
                                var texture = ImageTexture.createFromImage(image);
                                if (texture != null) {
                                    control.addThemeIconOverride(snakeCaseName, texture);
                                    continue;
                                }
                                else {
                                    throw "Failed to create Texture2D from image for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                                }
                            }
                            else {
                                throw "Failed to load image from file for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                            }
                        }
                    }
                    throw "Unknown field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                }
            }
        }
    }

    private function constructChildren(element: Element, xml: Xml): Void {
        var children = xml.elements();
        for (child in children) {
            var childElement = construct(child);
            if (childElement != null) {
                element.addChild(childElement);
            }
            else {
                throw "Unknown child element: " + child.nodeName;
            }
        }
    }

    private function isAnElementClass(classInfo: Class<Dynamic>): Bool {
        var superClass = Type.getSuperClass(classInfo);
        if (Type.getClassName(superClass) == "Class<sunaba.core.Element>") {
            return true;
        }
        else if (superClass != null) {
            var res = isAnElementClass(superClass);
            if (res) {
                return true;
            }
        }
        return false;
    }

    private function camelToPascal(str:String):String {
        if (str == null || str.length == 0) return str;
        return str.charAt(0).toUpperCase() + str.substr(1);
    }

    private function camelToSnake(input: String): String {
        var result = "";
        for (i in 0...input.length) {
            var c = input.charAt(i);
            if (i > 0 && c >= "A" && c <= "Z") {
                result += "_";
            }
            result += c.toLowerCase();
        }
        return result;
    }
}