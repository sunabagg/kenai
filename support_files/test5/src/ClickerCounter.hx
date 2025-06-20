package support_files.test5.src;

import sunaba.ui.Widget;

class ClickerCounter extends Widget {
    var label: sunaba.ui.Label;
    
    override function init() {
        load("app://assets/ClickerCounter.suml");
    }

    function onClick() {
        
    }
}