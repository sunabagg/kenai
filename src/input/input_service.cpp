#include "input_service.h"

namespace sunaba::input {
    void InputServiceSignalWrapper::_bind_methods() {
        ClassDB::bind_method(D_METHOD("joy_connection_changed", "device", "connected"), &InputServiceSignalWrapper::joy_connection_changed);
    }

    void InputServiceSignalWrapper::joy_connection_changed(int device, bool connected) {
        if (InputService::getJoyConnectionChangedEvent() != nullptr) {
            Array args;
            args.append(device);
            args.append(connected);
            InputService::getJoyConnectionChangedEvent()->emit(args);
        }
    }

    void bindInputService(sol::state& lua) {
        lua.new_usertype<InputService>("InputService",
            sol::no_constructor,
            sol::base_classes, sol::bases<Service>(),
            "emulateMouseFromTouch", sol::property(
                &InputService::getEmulateMouseFromTouch,
                &InputService::setEmulateMouseFromTouch
            ),
            "emulateTouchFromMouse", sol::property(
                &InputService::getEmulateTouchFromMouse,
                &InputService::setEmulateTouchFromMouse
            ),
            "mouseMode", sol::property(
                &InputService::getMouseMode,
                &InputService::setMouseMode
            ),
            "useAccumulatedInput", sol::property(
                &InputService::getUseAccumulatedInput,
                &InputService::setUseAccumulatedInput
            ),
            "joyConnectionChanged", sol::property(
                &InputService::getJoyConnectionChangedEvent,
                &InputService::setJoyConnectionChangedEvent
            ),
            "actionPress", sol::factories(
                [](std::string action) { InputService::actionPress(action); },
                [](std::string action, float strength) { InputService::actionPress(action, strength); }
            ),
            "actionRelease", &InputService::actionRelease,
            "addJoyMapping", sol::factories(
                [](std::string mapping) { InputService::addJoyMapping(mapping); },
                [](std::string mapping, bool updateExisting) { InputService::addJoyMapping(mapping, updateExisting); }
            ),
            "flushBufferedEvents", &InputService::flushBufferedEvents,
            "getAccelerometer", &InputService::getAccelerometer,
            "getActionRawStrength", sol::factories(
                [](std::string action) { InputService::getActionRawStrength(action); },
                [](std::string action, bool exactMatch) { InputService::getActionRawStrength(action, exactMatch); }
            ),
            "getActionStrength", sol::factories(
                [](std::string action) { InputService::getActionStrength(action); },
                [](std::string action, bool exactMatch) { InputService::getActionStrength(action, exactMatch); }
            ),
            "getAxis", &InputService::getAxis,
            "getConnectedJoypads", &InputService::getConnectedJoypads,
            "getCurrentCursorShape", &InputService::getCurrentCursorShape,
            "getGravity", &InputService::getGravity,
            "getGyroscope", &InputService::getGyroscope,
            "getJoyAxis", &InputService::getJoyAxis,
            "getJoyGuid", &InputService::getJoyGuid,
            "getJoyInfo", &InputService::getJoyInfo,
            "getJoyName", &InputService::getJoyName,
            "getJoyVibrationDuration", &InputService::getJoyVibrationDuration,
            "getJoyVibrationStrength", &InputService::getJoyVibrationStrength,
            "getLastMouseScreenVelocity", &InputService::getLastMouseScreenVelocity,
            "getLastMouseVelocity", &InputService::getLastMouseVelocity
        );
    }
}