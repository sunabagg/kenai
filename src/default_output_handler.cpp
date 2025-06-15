#include "console.h"

#include <godot_cpp/classes/resource_loader.hpp>

using namespace sunaba;

DefaultOutputHandler::DefaultOutputHandler() {
    output_label = memnew(RichTextLabel);
    input_line_edit = memnew(LineEdit);
    container = memnew(VBoxContainer);

    auto resource_loader = ResourceLoader::get_singleton();
    if (resource_loader) {
        Ref<Theme> theme = resource_loader->load("res://themes/default_theme.tres");
        if (theme.is_valid()) {
            set_theme(theme);
        }
    }

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

Console* DefaultOutputHandler::get_console() const {
    return console;
}

void DefaultOutputHandler::set_console(Console* console) {
    this->console = console;
    if (console) {
        console->default_output_handler = this;
    }
}

void DefaultOutputHandler::_bind_methods() {
    ClassDB::bind_method(D_METHOD("on_line_edit_text_submitted", "text"), &DefaultOutputHandler::on_line_edit_text_submitted);
}