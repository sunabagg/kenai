#ifndef CONSOLE_H
#define CONSOLE_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/rich_text_label.hpp>
#include <godot_cpp/classes/line_edit.hpp>
#include <sol/state.hpp>
#include <map>

#include "core/io/io_manager.h"

using namespace godot;

namespace sunaba
{
    class DefaultOutputHandler;

    class Console : public Node {
        GDCLASS(Console, Node)
    protected:
        static void _bind_methods();
    public:
        Console();
        ~Console();

        sol::state global_state;

        sunaba::core::io::IoManager* ioManager;

        String shell_path;

        std::map<std::string, std::function<void(const std::vector<std::string> &args)>> commands;

        std::vector<std::string> path;

        std::vector<std::function<void(const std::string &output)>> output_callbacks;

        std::vector<std::function<void()>> back_to_prompt_callbacks;

        bool prompt_available = true;

        DefaultOutputHandler* default_output_handler = nullptr;

        void display_default_output();

        void start_shell(const String &path);

        void print(const std::string &message);

        void run_command(const String &command, std::vector<std::string> args = {});

        void register_command(const std::string &name, const std::function<void(const std::vector<std::string> &args)> &callback);
        
        void unregister_command(const std::string &name);

        void run_executable(const std::string &path, const std::vector<std::string> &args);

        void run_executable_dir(const std::string &path, const std::vector<std::string> &args);
    };

    class DefaultOutputHandler : public Control {
        GDCLASS(DefaultOutputHandler, Control)
        private:
            Console* console;
        protected:
            static void _bind_methods();
        public:
            DefaultOutputHandler();
            ~DefaultOutputHandler();

            RichTextLabel* output_label;
            LineEdit* input_line_edit;
            VBoxContainer* container;

            Console* get_console() const;
            void set_console(Console* console);

            void on_line_edit_text_submitted(const String &text);
    };
}

#endif //CONSOLE_H