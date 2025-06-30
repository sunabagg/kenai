#ifndef INPUT_SERVICE_H
#define INPUT_SERVICE_H

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#include "../core/service.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::input {
    void bindInputService(sol::state& lua);

    class InputService : public Service {
        private:
            static Input* inputSingleton;

        public:
            static Input* getInstance() {
                if (inputSingleton == nullptr) {
                    inputSingleton = Input::get_singleton();
                }
                return inputSingleton;
            }

            static bool getEmulateMouseFromTouch() {
                return inputSingleton->is_emulating_mouse_from_touch();
            }

            static void setEmulateMouseFromTouch(bool value) {
                inputSingleton->set_emulate_touch_from_mouse(value);
            }

            static bool getEmulateTouchFromMouse() {
                return inputSingleton->is_emulating_touch_from_mouse();
            }

            static void setEmulateTouchFromMouse(bool value) {
                inputSingleton->set_emulate_touch_from_mouse(value);
            }

            static int getMouseMode() {
                return inputSingleton->get_mouse_mode();
            }

            static void setMouseMode(int value) {
                inputSingleton->set_mouse_mode(static_cast<Input::MouseMode>(value));
            }

            static bool getUseAccumulatedInput() {
                return inputSingleton->is_using_accumulated_input();
            }

            static void setUseAccumulatedInput(bool value) {
                inputSingleton->set_use_accumulated_input(value);
            }
    };
}

#endif