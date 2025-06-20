package support_files.test5.src;

import sunaba.ui.Button;
import sunaba.ui.Button.ButtonAbstract;
import sunaba.ui.Label;
import sunaba.ui.Widget;

class ClickerCounter extends Widget {
    var label: Label;
    var counter: Int = 0;
    
    override function init() {
        load("app://assets/ClickerCounter.suml");
        label = Label.toLabel(
            rootElement.find(
                "/centerContainer/vBoxContainer/clickCounterLabel"
            )
        );
        var buttonA : ButtonAbstract = rootElement.find(
            "/centerContainer/vBoxContainer/clickerButton"
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