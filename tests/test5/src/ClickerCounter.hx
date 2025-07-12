package;

import kenai.ui.Button;
import kenai.ui.Button.ButtonAbstract;
import kenai.ui.Label;
import kenai.ui.Widget;

class ClickerCounter extends Widget {
    var label: Label;
    var counter: Int = 0;
    
    override function init() {
        load("app://ClickerCounter.suml");
        var labelElement = rootElement.find(
            "centerContainer/vboxContainer/clickCounterLabel"
        );
        if (labelElement.isNull()) {
            throw "Label element not found in ClickerCounter layout.";
        }
        label = Label.toLabel(
            labelElement
        );
        var buttonA : ButtonAbstract = rootElement.find(
            "centerContainer/vboxContainer/clickerButton"
        );
        var button : Button= buttonA;
        button.pressed.connect(() -> {
            onClick();
        });
    }

    function onClick() {
        counter++;
        if (label != null) {
            label.text = "You clicked me " + counter + " times!";
        }
    }
}