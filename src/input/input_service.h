#ifndef INPUT_SERVICE_H
#define INPUT_SERVICE_H

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#include "../core/service.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

StringName toStringName(std::string str) {
    return StringName(String(str.c_str()));
}

namespace sunaba::input {
    void bindInputService(sol::state& lua);

    class InputServiceSignalWrapper : public Object {
        GDCLASS(InputServiceSignalWrapper, Object)
        protected:
            static void _bind_methods();
        public:
            InputServiceSignalWrapper() = default;
            ~InputServiceSignalWrapper() = default;

            void joy_connection_changed(int device, bool connected);
    };

    class InputService : public Service {
        private:
            static Input* inputSingleton;
            static InputServiceSignalWrapper* signalWrapper;

            static void connectInputServiceSignals() {
                if (signalWrapper == nullptr) {
                    signalWrapper = new InputServiceSignalWrapper();
                }

                inputSingleton->connect("joy_connection_changed", Callable(signalWrapper, "joy_connection_changed"));
            }
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

            static Event* joyConnectionChangedEvent;
            static Event* getJoyConnectionChangedEvent() {
                if (joyConnectionChangedEvent == nullptr) {
                    joyConnectionChangedEvent = new Event();
                }
                return joyConnectionChangedEvent;
            }
            static void setJoyConnectionChangedEvent(Event* e) {
                joyConnectionChangedEvent = e;
            }

            static void actionPress(std::string action, float strength = 1.0f) {
                inputSingleton->action_press(toStringName(action), strength);
            }

            static void actionRelease(std::string action) {
                inputSingleton->action_release(toStringName(action));
            }

            void addJoyMapping(std::string mapping, bool updateExisting = false) {
                inputSingleton->add_joy_mapping(mapping.c_str(), updateExisting);
            }

            void flushBufferedEvents() {
                inputSingleton->flush_buffered_events();
            }

            Vector3 getAccelerometer() {
                return inputSingleton->get_accelerometer();
            }

            float getActionRawStrength(std::string action, bool exactMatch = false) {
                return inputSingleton->get_action_raw_strength(toStringName(action), exactMatch);
            }
    };
}

#endif