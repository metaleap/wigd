#pragma once

#include <stdint.h>




// wi::initializer

typedef enum WI_INITIALIZED_SYSTEM {
  WI_INITIALIZED_SYSTEM_FONT,
  WI_INITIALIZED_SYSTEM_IMAGE,
  WI_INITIALIZED_SYSTEM_INPUT,
  WI_INITIALIZED_SYSTEM_RENDERER,
  WI_INITIALIZED_SYSTEM_TEXTUREHELPER,
  WI_INITIALIZED_SYSTEM_HAIRPARTICLESYSTEM,
  WI_INITIALIZED_SYSTEM_EMITTEDPARTICLESYSTEM,
  WI_INITIALIZED_SYSTEM_OCEAN,
  WI_INITIALIZED_SYSTEM_GPUSORTLIB,
  WI_INITIALIZED_SYSTEM_GPUBVH,
  WI_INITIALIZED_SYSTEM_PHYSICS,
  WI_INITIALIZED_SYSTEM_LUA,
  WI_INITIALIZED_SYSTEM_AUDIO,
  WI_INITIALIZED_SYSTEM_TRAILRENDERER,

  WI_INITIALIZED_SYSTEM_COUNT

} WI_INITIALIZED_SYSTEM;




// DirectXMath.h

typedef struct WI_XMFLOAT4 {
  float x;
  float y;
  float z;
  float w;
} WI_XMFLOAT4;


typedef struct WI_XMFLOAT3 {
  float x;
  float y;
  float z;
} WI_XMFLOAT3;


typedef struct WI_XMFLOAT2 {
  float x;
  float y;
} WI_XMFLOAT2;




// wi::input


typedef enum WI_GAMEPAD_ANALOG {
  WI_GAMEPAD_ANALOG_THUMBSTICK_L,
  WI_GAMEPAD_ANALOG_THUMBSTICK_R,
  WI_GAMEPAD_ANALOG_TRIGGER_L,
  WI_GAMEPAD_ANALOG_TRIGGER_R,

} WI_GAMEPAD_ANALOG;


typedef struct WiMouseState {
  WI_XMFLOAT2 position;
  WI_XMFLOAT2 delta_position;
  float delta_wheel;
  float pressure;
  bool left_button_press;
  bool middle_button_press;
  bool right_button_press;
} WiMouseState;


typedef enum WI_BUTTON {
  WI_BUTTON_NONE = 0,

  WI_DIGIT_RANGE_START = 48, // digit 0

  WI_CHARACTER_RANGE_START = 65, // letter A

  WI_GAMEPAD_RANGE_START = 256, // do not use!

  WI_GAMEPAD_BUTTON_UP,
  WI_GAMEPAD_BUTTON_LEFT,
  WI_GAMEPAD_BUTTON_DOWN,
  WI_GAMEPAD_BUTTON_RIGHT,
  WI_GAMEPAD_BUTTON_1,
  WI_GAMEPAD_BUTTON_2,
  WI_GAMEPAD_BUTTON_3,
  WI_GAMEPAD_BUTTON_4,
  WI_GAMEPAD_BUTTON_5,
  WI_GAMEPAD_BUTTON_6,
  WI_GAMEPAD_BUTTON_7,
  WI_GAMEPAD_BUTTON_8,
  WI_GAMEPAD_BUTTON_9,
  WI_GAMEPAD_BUTTON_10,
  WI_GAMEPAD_BUTTON_11,
  WI_GAMEPAD_BUTTON_12,
  WI_GAMEPAD_BUTTON_13,
  WI_GAMEPAD_BUTTON_14,

  // Check analog presses like a button:
  WI_GAMEPAD_ANALOG_THUMBSTICK_L_AS_BUTTON_UP,
  WI_GAMEPAD_ANALOG_THUMBSTICK_L_AS_BUTTON_LEFT,
  WI_GAMEPAD_ANALOG_THUMBSTICK_L_AS_BUTTON_DOWN,
  WI_GAMEPAD_ANALOG_THUMBSTICK_L_AS_BUTTON_RIGHT,
  WI_GAMEPAD_ANALOG_THUMBSTICK_R_AS_BUTTON_UP,
  WI_GAMEPAD_ANALOG_THUMBSTICK_R_AS_BUTTON_LEFT,
  WI_GAMEPAD_ANALOG_THUMBSTICK_R_AS_BUTTON_DOWN,
  WI_GAMEPAD_ANALOG_THUMBSTICK_R_AS_BUTTON_RIGHT,
  WI_GAMEPAD_ANALOG_TRIGGER_L_AS_BUTTON,
  WI_GAMEPAD_ANALOG_TRIGGER_R_AS_BUTTON,

  // Xbox mapping of generic codes:
  WI_GAMEPAD_BUTTON_XBOX_X = WI_GAMEPAD_BUTTON_1,
  WI_GAMEPAD_BUTTON_XBOX_A = WI_GAMEPAD_BUTTON_2,
  WI_GAMEPAD_BUTTON_XBOX_B = WI_GAMEPAD_BUTTON_3,
  WI_GAMEPAD_BUTTON_XBOX_Y = WI_GAMEPAD_BUTTON_4,
  WI_GAMEPAD_BUTTON_XBOX_L1 = WI_GAMEPAD_BUTTON_5,
  WI_GAMEPAD_BUTTON_XBOX_LT = WI_GAMEPAD_ANALOG_TRIGGER_L_AS_BUTTON,
  WI_GAMEPAD_BUTTON_XBOX_R1 = WI_GAMEPAD_BUTTON_6,
  WI_GAMEPAD_BUTTON_XBOX_RT = WI_GAMEPAD_ANALOG_TRIGGER_R_AS_BUTTON,
  WI_GAMEPAD_BUTTON_XBOX_L3 = WI_GAMEPAD_BUTTON_7,
  WI_GAMEPAD_BUTTON_XBOX_R3 = WI_GAMEPAD_BUTTON_8,
  WI_GAMEPAD_BUTTON_XBOX_BACK = WI_GAMEPAD_BUTTON_9,
  WI_GAMEPAD_BUTTON_XBOX_START = WI_GAMEPAD_BUTTON_10,

  // Playstation mapping of generic codes:
  WI_GAMEPAD_BUTTON_PLAYSTATION_SQUARE = WI_GAMEPAD_BUTTON_1,
  WI_GAMEPAD_BUTTON_PLAYSTATION_CROSS = WI_GAMEPAD_BUTTON_2,
  WI_GAMEPAD_BUTTON_PLAYSTATION_CIRCLE = WI_GAMEPAD_BUTTON_3,
  WI_GAMEPAD_BUTTON_PLAYSTATION_TRIANGLE = WI_GAMEPAD_BUTTON_4,
  WI_GAMEPAD_BUTTON_PLAYSTATION_L1 = WI_GAMEPAD_BUTTON_5,
  WI_GAMEPAD_BUTTON_PLAYSTATION_L2 = WI_GAMEPAD_ANALOG_TRIGGER_L_AS_BUTTON,
  WI_GAMEPAD_BUTTON_PLAYSTATION_R1 = WI_GAMEPAD_BUTTON_6,
  WI_GAMEPAD_BUTTON_PLAYSTATION_R2 = WI_GAMEPAD_ANALOG_TRIGGER_R_AS_BUTTON,
  WI_GAMEPAD_BUTTON_PLAYSTATION_L3 = WI_GAMEPAD_BUTTON_7,
  WI_GAMEPAD_BUTTON_PLAYSTATION_R3 = WI_GAMEPAD_BUTTON_8,
  WI_GAMEPAD_BUTTON_PLAYSTATION_SHARE = WI_GAMEPAD_BUTTON_9,
  WI_GAMEPAD_BUTTON_PLAYSTATION_OPTION = WI_GAMEPAD_BUTTON_10,
  WI_GAMEPAD_BUTTON_PLAYSTATION_SELECT = WI_GAMEPAD_BUTTON_PLAYSTATION_SHARE,
  WI_GAMEPAD_BUTTON_PLAYSTATION_START = WI_GAMEPAD_BUTTON_PLAYSTATION_OPTION,

  WI_GAMEPAD_RANGE_END = 512, // do not use!

  WI_MOUSE_BUTTON_LEFT,
  WI_MOUSE_BUTTON_RIGHT,
  WI_MOUSE_BUTTON_MIDDLE,

  // Detect mouse scroll like a button:
  WI_MOUSE_SCROLL_AS_BUTTON_UP,
  WI_MOUSE_SCROLL_AS_BUTTON_DOWN,

  WI_KEYBOARD_BUTTON_UP,
  WI_KEYBOARD_BUTTON_DOWN,
  WI_KEYBOARD_BUTTON_LEFT,
  WI_KEYBOARD_BUTTON_RIGHT,
  WI_KEYBOARD_BUTTON_SPACE,
  WI_KEYBOARD_BUTTON_RSHIFT,
  WI_KEYBOARD_BUTTON_LSHIFT,
  WI_KEYBOARD_BUTTON_F1,
  WI_KEYBOARD_BUTTON_F2,
  WI_KEYBOARD_BUTTON_F3,
  WI_KEYBOARD_BUTTON_F4,
  WI_KEYBOARD_BUTTON_F5,
  WI_KEYBOARD_BUTTON_F6,
  WI_KEYBOARD_BUTTON_F7,
  WI_KEYBOARD_BUTTON_F8,
  WI_KEYBOARD_BUTTON_F9,
  WI_KEYBOARD_BUTTON_F10,
  WI_KEYBOARD_BUTTON_F11,
  WI_KEYBOARD_BUTTON_F12,
  WI_KEYBOARD_BUTTON_ENTER,
  WI_KEYBOARD_BUTTON_ESCAPE,
  WI_KEYBOARD_BUTTON_HOME,
  WI_KEYBOARD_BUTTON_RCONTROL,
  WI_KEYBOARD_BUTTON_LCONTROL,
  WI_KEYBOARD_BUTTON_DELETE,
  WI_KEYBOARD_BUTTON_BACKSPACE,
  WI_KEYBOARD_BUTTON_PAGEDOWN,
  WI_KEYBOARD_BUTTON_PAGEUP,
  WI_KEYBOARD_BUTTON_NUMPAD0,
  WI_KEYBOARD_BUTTON_NUMPAD1,
  WI_KEYBOARD_BUTTON_NUMPAD2,
  WI_KEYBOARD_BUTTON_NUMPAD3,
  WI_KEYBOARD_BUTTON_NUMPAD4,
  WI_KEYBOARD_BUTTON_NUMPAD5,
  WI_KEYBOARD_BUTTON_NUMPAD6,
  WI_KEYBOARD_BUTTON_NUMPAD7,
  WI_KEYBOARD_BUTTON_NUMPAD8,
  WI_KEYBOARD_BUTTON_NUMPAD9,
  WI_KEYBOARD_BUTTON_MULTIPLY,
  WI_KEYBOARD_BUTTON_ADD,
  WI_KEYBOARD_BUTTON_SEPARATOR,
  WI_KEYBOARD_BUTTON_SUBTRACT,
  WI_KEYBOARD_BUTTON_DECIMAL,
  WI_KEYBOARD_BUTTON_DIVIDE,
  WI_KEYBOARD_BUTTON_TAB,
  WI_KEYBOARD_BUTTON_TILDE,
  WI_KEYBOARD_BUTTON_INSERT,
  WI_KEYBOARD_BUTTON_ALT,
  WI_KEYBOARD_BUTTON_ALTGR,

  // must be the last entry
  WI_BUTTON_ENUM_SIZE

} WI_BUTTON;


typedef struct WiKeyboardState {
  bool buttons[WI_BUTTON_ENUM_SIZE] = {}; // it contains pressed buttons as "keyboard/typewriter" like, so no continuous presses
} WiKeyboardState;




// wi::graphics

typedef struct WiViewport {
  float top_left_x;
  float top_left_y;
  float width;
  float height;
  float min_depth;
  float max_depth;
} WiViewport;

typedef struct WiRect {
  int32_t left;
  int32_t top;
  int32_t right;
  int32_t bottom;
} WiRect;
