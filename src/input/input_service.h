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
                    connectInputServiceSignals();
                }
                return inputSingleton;
            }

            static bool getEmulateMouseFromTouch() {
                return getInstance()->is_emulating_mouse_from_touch();
            }

            static void setEmulateMouseFromTouch(bool value) {
                getInstance()->set_emulate_touch_from_mouse(value);
            }

            static bool getEmulateTouchFromMouse() {
                return getInstance()->is_emulating_touch_from_mouse();
            }

            static void setEmulateTouchFromMouse(bool value) {
                getInstance()->set_emulate_touch_from_mouse(value);
            }

            static int getMouseMode() {
                return getInstance()->get_mouse_mode();
            }

            static void setMouseMode(int value) {
                getInstance()->set_mouse_mode(static_cast<Input::MouseMode>(value));
            }

            static bool getUseAccumulatedInput() {
                return getInstance()->is_using_accumulated_input();
            }

            static void setUseAccumulatedInput(bool value) {
                getInstance()->set_use_accumulated_input(value);
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
                getInstance()->action_press(toStringName(action), strength);
            }

            static void actionRelease(std::string action) {
                getInstance()->action_release(toStringName(action));
            }

            static void addJoyMapping(std::string mapping, bool updateExisting = false) {
                getInstance()->add_joy_mapping(mapping.c_str(), updateExisting);
            }

            static void flushBufferedEvents() {
                getInstance()->flush_buffered_events();
            }

            static Vector3 getAccelerometer() {
                return getInstance()->get_accelerometer();
            }

            static float getActionRawStrength(std::string action, bool exactMatch = false) {
                return getInstance()->get_action_raw_strength(toStringName(action), exactMatch);
            }

            static float getActionStrength(std::string action, bool exactMatch = false) {
                getInstance()->get_action_strength(toStringName(action), exactMatch);
            }

            static float getAxis(std::string negativeAction, std::string positiveAction) {
                return getInstance()->get_axis(toStringName(negativeAction), toStringName(positiveAction));
            }

            static std::vector<int> getConnectedJoypads() {
                auto result = getInstance()->get_connected_joypads();
                std::vector<int> resultVector;
                for (size_t i = 0; i < result.size(); i++)
                {
                    resultVector.push_back(result[i]);
                }
                return resultVector;
            }

            static int getCurrentCursorShape() {
                return getInstance()->get_current_cursor_shape();
            }

            static Vector3 getGravity() {
                return getInstance()->get_gravity();
            }

            static Vector3 getGyroscope() {
                return getInstance()->get_gyroscope();
            }

            static float getJoyAxis(int device, int axis) {
                return getInstance()->get_joy_axis(device, static_cast<JoyAxis>(axis));
            }

            std::string getJoyGuid(int device) {
                return getInstance()->get_joy_guid(device).utf8().get_data();
            }

            Dictionary getJoyInfo(int device) {
                return getInstance()->get_joy_info(device);
            }
    };
}

#endif