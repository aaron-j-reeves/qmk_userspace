// config.h
#pragma once

#include "config_audio.h" // audio configurations
#include "config_joystick.h" // joystick configurations
#include "config_mousekey.h" // mousekey configurations
#include "config_rgb.h" // rgb configurations
#include "config_touchpad.h" // cirque touchpad configurations
#include 

#define SPLIT_POINTING_ENABLE
#define SPLIT_TRANSPORT_MIRROR

#define TAPPING_TERM 300
#define PERMISSIVE_HOLD
#define toggle 3

#define CAPS_WORD_INVERT_ON_SHIFT
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define COMBO_TERM 40
#define EXTRA_SHORT_COMBOS

#define LAYER_LOCK_IDLE_TIMEOUT 10000  // Turn off after 10 seconds.

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */


