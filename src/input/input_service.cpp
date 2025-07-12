#include "input_service.h"

// Add this definition at global scope (outside any function/namespace)
godot::Input *kenai::input::InputService::inputSingleton = nullptr;
kenai::input::InputServiceSignalWrapper *kenai::input::InputService::signalWrapper = nullptr;
kenai::core::Event *kenai::input::InputService::joyConnectionChangedEvent = nullptr;




namespace kenai::input {
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
            "joyConnectionChanged", sol::readonly_property(
                &InputService::getJoyConnectionChangedEvent//,
                //&InputService::setJoyConnectionChangedEvent
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
            "getLastMouseVelocity", &InputService::getLastMouseVelocity,
            "getMagnetometer", &InputService::getMagnetometer,
            "getMouseButtonMask", &InputService::getMouseButtonMask,
            "getVector",sol::factories(
                [](std::string negativeX, std::string positiveX, std::string negativeY, std::string positiveY) { return InputService::getVector(negativeX, positiveX, negativeY, positiveY); },
                [](std::string negativeX, std::string positiveX, std::string negativeY, std::string positiveY, bool deadzone) { return InputService::getVector(negativeX, positiveX, negativeY, positiveY, deadzone); }
            ),
            "isActionJustPressed", sol::factories(
                [](std::string action) { return InputService::isActionJustPressed(action); },
                [](std::string action, bool exactMatch) { return InputService::isActionJustPressed(action, exactMatch); }
            ),
            "isActionJustReleased", sol::factories(
                [](std::string action) { return InputService::isActionJustReleased(action); },
                [](std::string action, bool exactMatch) { return InputService::isActionJustReleased(action, exactMatch); }
            ),
            "isActionPressed", sol::factories(
                [](std::string action) { return InputService::isActionPressed(action); },
                [](std::string action, bool exactMatch) { return InputService::isActionPressed(action, exactMatch); }
            ),
            "isAnythingPressed", &InputService::isAnythingPressed,
            "isJoyButtonPressed", &InputService::isJoyButtonPressed,
            "isJoyKnown", &InputService::isJoyKnown,
            "isKeyLabelPressed", &InputService::isKeyLabelPressed,
            "isKeyPressed", &InputService::isKeyPressed,
            "isMouseButtonPressed", &InputService::isMouseButtonPressed,
            "isPhysicalKeyPressed", &InputService::isPhysicalKeyPressed,
            "parseInputEvent", &InputService::parseInputEvent,
            "removeJoyMapping", &InputService::removeJoyMapping,
            "setAccelerometer", &InputService::setAccelerometer,
            "setCustomMouseCursor", sol::factories(
                [](kenai::core::Resource* image) { InputService::setCustomMouseCursor(image); },
                [](kenai::core::Resource* image, int shape) { InputService::setCustomMouseCursor(image, shape); },
                [](kenai::core::Resource* image, int shape, Vector2 hotspot) { InputService::setCustomMouseCursor(image, shape, hotspot); }
            ),
            "setDefaultCursorShape", sol::factories(
                []() { InputService::setDeaultCursorShape(); },
                [](int shape) { InputService::setDeaultCursorShape(shape); }
            ),
            "setGravity", &InputService::setGravity,
            "setGyroscope", &InputService::setGyroscope,
            "setMagnetometer", &InputService::setMagnetometer,
            "shouldIgnoreDevice", &InputService::shouldIgnoreDevice,
            "startJoyVibration", sol::factories(
                [](int device, float weakMagnitude, float strongMagnitude) { InputService::startJoyVibration(device, weakMagnitude, strongMagnitude); },
                [](int device, float weakMagnitude, float strongMagnitude, float duration) { InputService::startJoyVibration(device, weakMagnitude, strongMagnitude, duration); }
            ),
            "stopJoyVibration", &InputService::stopJoyVibration,
            "vibrateHandheld", sol::factories(
                []() { InputService::vibrateHandheld(); },
                [](int durationMs) { InputService::vibrateHandheld(durationMs); },
                [](int durationMs, float amplitude) { InputService::vibrateHandheld(durationMs, amplitude); }
            ),
            "warpMouse", &InputService::warpMouse
        );
    }
}