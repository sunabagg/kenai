#include "bind_input_classes.h"
#include "input_event.h"
#include "input_event_from_window.h"
#include "input_event_with_modifiers.h"
#include "input_event_action.h"
#include "input_event_gesture.h"
#include "input_event_magnify_gesture.h"
#include "input_event_pan_gesture.h"
#include "input_event_joypad_button.h"
#include "input_event_joypad_motion.h"
#include "input_event_key.h"
#include "input_event_mouse.h"
#include "input_event_mouse_button.h"
#include "input_event_mouse_motion.h"
#include "input_event_screen_drag.h"
#include "input_event_screen_touch.h"
#include "shortcut.h"

void lucidfx::input::bindInputClasses(sol::state& lua) {
    bindInputEvent(lua);
    bindInputEventFromWindow(lua);
    bindInputEventWithModifiers(lua);
    bindInputEventAction(lua);
    bindInputEventGesture(lua);
    bindInputEventMagnifyGesture(lua);
    bindInputEventPanGesture(lua);
    bindInputEventJoypadButton(lua);
    bindInputEventJoypadMotion(lua);
    bindInputEventKey(lua);
    bindInputEventMouse(lua);
    bindInputEventMouseButton(lua);
    bindInputEventMouseMotion(lua);
    bindInputEventScreenDrag(lua);
    bindInputEventScreenTouch(lua);
    bindShortcut(lua);
}
