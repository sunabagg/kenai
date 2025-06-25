package sunaba.ui;

import sunaba.desktop.PopupMenu;
import sunaba.core.GlobalObjectStack;
import haxe.DynamicAccess;
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
    private var elementdb = [];

    public function new() {
        io = untyped __lua__("_G.ioManager");
        rootElement = new Control();
        rootElement.theme = Theme.getDefaultTheme();

        init();
    }

    public function init() {
        
    }

    public function load(path: String): Void {
        var file = io.loadText(path);
        if (file != null && file.length > 0) {
            try {
                parseMarkup(file);
            }
            catch (e: Dynamic) {
                Sys.println("Error parsing markup: " + e);
                throw e;
            }
        }
        else {
            Sys.println("Failed to load file: " + path);
            throw "Failed to load file: " + path;
        }
    }

    public function parseMarkup(markup: String): Void {
        var xml = Xml.parse(markup);
        instantiate(xml);
    }

    private function instantiate(xml: Xml): Void {
        if (rootElement != null && !keepChildren) {
            var children : Array<Element> = rootElement.getChildren();
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
                    rootElement.setAnchorsAndOffsetsPreset(LayoutPreset.fullRect, LayoutPresetMode.keepSize, 0);
                    rootElement.sizeFlagsHorizontal = SizeFlags.fill;
                    rootElement.sizeFlagsVertical = SizeFlags.fill;
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
            elementdb.push(element);
            // stupid hack to make sure the element is added to the global object stack
            // so that the program doesn't fucking crash
            GlobalObjectStack.getSingleton().stack.push(new sunaba.core.StackHandle(element));
            if (element != null && element.isNull() == false) {
                rootElement.addChild(element);
            }
            else {
                throw "Unknown element: " + node.nodeName;
            }
        }
    }

    private function construct(xml: Xml) : Element {
        var className = xml.nodeName;
        className = camelToPascal(className);
        var classType : Class<Dynamic> = untyped __lua__("_G[className]");
        if (classType != null) {
            //Sys.println("Constructing element of class: " + className);

            var instance = untyped __lua__("classType.new()");
            if (instance != null) {
                var element : Element = cast instance;
                setObjectValues(element, xml);
                if (className == "PopupMenu") {
                    constructMenu(PopupMenu.toPopupMenu(element), xml);
                }
                else if (className == "MenuButton") {
                    var menuButton = MenuButton.toMenuButton(element);
                    constructMenu(menuButton.getPopup(), xml);
                }
                else {
                    constructChildren(element, xml);
                }
                if (element.name == null) {
                    var nameAtt = xml.get("name");
                    if (nameAtt != null) {
                        element.name = nameAtt;
                    }
                }
                return element;
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
            else if (attributeName == "fullRect") {
                var control = Control.toControl(element);
                if (control.isNull() == false) {
                    if (attributeValue == "true") {
                        control.setAnchorsPreset(LayoutPreset.fullRect, true);
                    }
                }
            }
            else {
                if (hasField(element, attributeName)) {
                    var currentValue = field(element, attributeName);
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
                        setProperty(element, attributeName, b);
                    }
                    else if (Std.isOfType(currentValue, Int)) {
                        var attrArr = attributeValue.split(".");
                        var value = attrArr[attrArr.length - 1];
                        attrArr.resize(attrArr.length - 1);
                        var enumName = attrArr.join(".");
                        if (enumName != "") {
                            var enum_ = Type.resolveEnum(enumName);
                            if (enum_ != null) {
                                var enumValue : Int = cast field(enum_, value);
                                if (enumValue != null) {
                                    setProperty(element, attributeName, enumValue);
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
                            if (attributeValue == "$FILL_BOTTOM_RIGHT") {
                                attributeValue = "1"; // Special case for $FILL_BOTTOM_RIGHT
                            }
                            if (attributeValue == "$FILL_TOP_LEFT") {
                                attributeValue = "0"; // Special case for $FILL_TOP_LEFT
                            }
                            setProperty(element, attributeName, Std.parseInt(attributeValue));
                        }
                    }
                    else if (Std.isOfType(currentValue, Float)) {
                        setProperty(element, attributeName, Std.parseFloat(attributeValue));
                    }
                    else if (Std.isOfType(currentValue, String)) {
                        setProperty(element, attributeName, attributeValue);
                    }
                    else if (Std.isOfType(currentValue, Vector2)) {
                        var xy = attributeValue.split(",");
                        if (xy.length == 2) {
                            var x = Std.parseFloat(xy[0]);
                            var y = Std.parseFloat(xy[1]);
                            setProperty(element, attributeName, new Vector2(x, y));
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
                            setProperty(element, attributeName, new Vector3(x, y, z));
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
                            setProperty(element, attributeName, new Vector4(x, y, z, w));
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
                            setProperty(element, attributeName, new Vector2i(x, y));
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
                            setProperty(element, attributeName, new Vector3i(x, y, z));
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
                            setProperty(element, attributeName, new Vector4i(x, y, z, w));
                        }
                        else {
                            throw "Invalid Vector4i value for field '" + attributeName + "' in element '" + Type.getClassName(Type.getClass(element)) + "'";
                        }
                    }
                    else if (Std.isOfType(currentValue, Color)) {
                        var color = Color.html(attributeValue);
                        if (color != null) {
                            setProperty(element, attributeName, color);
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
                                setProperty(element, attributeName, texture);
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
                                setProperty(element, attributeName, texture);
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

    private function constructMenu(menu: PopupMenu, xml: Xml) {
        var children = xml.elements();
        for (child in children) {
            if (child.nodeName == "menuItem") {
                var attributes = child.attributes();
                var label = xml.get("label");
                var id = menu.itemCount;
                menu.addItem(label, id);
                for (attrib in attributes) {
                    var attributeName = attrib;
                    var attributeValue = xml.get(attributeName);
                    if (attributeName == "icon") {
                        var image = Image.loadFromFile(attributeValue);
                        if (image != null) {
                            var texture = ImageTexture.createFromImage(image);
                            if (texture != null) {
                                menu.setItemIcon(id, texture);
                            }
                            else {
                                throw "Failed to create Texture2D from image for field '" + attributeName + "' in menuItem";
                            }
                        }
                        else {
                            throw "Failed to load image from file for field '" + attributeName + "' in menuItem";
                        }
                    }
                    else if (attributeName == "checkable") {
                        var checkable : Bool = false;
                        if (attributeValue == "true") {
                            checkable = true;
                        }
                        else if (attributeValue == "false") {
                            checkable = false;
                        }
                        else {
                            throw "Invalid boolean value for field '" + attributeName + "' in menuItem";
                        }
                        menu.setItemAsCheckable(id, checkable);
                    }
                    else if (attributeName == "radioCheckable") {
                        var radioCheckable : Bool = false;
                        if (attributeValue == "true") {
                            radioCheckable = true;
                        }
                        else if (attributeValue == "false") {
                            radioCheckable = false;
                        }
                        else {
                            throw "Invalid boolean value for field '" + attributeName + "' in menuItem";
                        }
                        menu.setItemAsRadioCheckable(id, radioCheckable);
                    }
                    else if (attributeName == "separator") {
                        var separator : Bool = false;
                        if (attributeValue == "true") {
                            separator = true;
                        }
                        else if (attributeValue == "false") {
                            separator = false;
                        }
                        else {
                            throw "Invalid boolean value for field '" + attributeName + "' in menuItem";
                        }
                        menu.setItemAsSeparator(id, separator);
                    }
                    else if (attributeName == "checked") {
                        var checked : Bool = false;
                        if (attributeValue == "true") {
                            checked = true;
                        }
                        else if (attributeValue == "false") {
                            checked = false;
                        }
                        else {
                            throw "Invalid boolean value for field '" + attributeName + "' in menuItem";
                        }
                        menu.setItemChecked(id, checked);
                    }
                    else if (attributeName == 'disabled') {
                        var disabled : Bool = false;
                        if (attributeValue == "true") {
                            disabled = true;
                        }
                        else if (attributeValue == "false") {
                            disabled = false;
                        }
                        else {
                            throw "Invalid boolean value for field '" + attributeName + "' in menuItem";
                        }
                        menu.setItemDisabled(id, disabled);
                    }
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

    private inline function hasField(object: Any, field: String): Bool {
        var obj = object;
        return untyped __lua__("obj[field] ~= nil") || Reflect.hasField(obj, field);
    }

    private function field(obj: Any, field: String): Dynamic {
        if (untyped __lua__("obj[field] ~= nil")) {
            return untyped __lua__("obj[field]");
        }
        return Reflect.field(obj, field);
    }

    private inline function setProperty(obj: Any, field: String, value: Dynamic): Void {
        if (untyped __lua__("obj[field] ~= nil")) {
            untyped __lua__("obj[field] = value");
        }
        else {
            Reflect.setProperty(obj, field, value);
        }
    }

    private function isAnElementClass(classInfo: Class<Dynamic>): Bool {
        var isTrue : Bool = untyped __lua__("classInfo['isElementType'] ~= nil");
        if (isTrue == true) {
            return true;
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