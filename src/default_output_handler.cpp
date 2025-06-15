#include "console.h"

using namespace sunaba;

DefaultOutputHandler::DefaultOutputHandler() {
    output_label = memnew(RichTextLabel);
    input_line_edit = memnew(LineEdit);
    container = memnew(VBoxContainer);

    container->add_child(output_label);
    container->add_child(input_line_edit);
    
    add_child(container);

    output_label->set_v_size_flags(Control::SIZE_EXPAND_FILL);
    input_line_edit->set_h_size_flags(Control::SIZE_EXPAND_FILL);

    input_line_edit->connect("text_submitted", Callable(this, "on_line_edit_text_submitted"));
}

DefaultOutputHandler::~DefaultOutputHandler() {
    if (console) {
        console->default_output_handler = nullptr;
    }
}

void DefaultOutputHandler::on_line_edit_text_submitted(const String &text) {
    if (console) {
        console->run_command(text);
    }
}