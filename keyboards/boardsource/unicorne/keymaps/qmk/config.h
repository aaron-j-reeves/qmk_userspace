// config.h
#pragma once

#define SPLIT_POINTING_ENABLE
#define SPLIT_TRANSPORT_MIRROR

#define EXTRA_SHORT_COMBOS

#if defined(AUDIO_ENABLE)
#    include "user_song_list.h"

#ifdef USER_SONG_LIST
#    if defined(STARTUP_SONG)
#    undef STARTUP_SONG
#    endif
#    define STARTUP_SONG        SONG(MEGALOVANIA_SHORT)
#    if defined(GOODBYE_SONG)
#    undef GOODBYE_SONG
#    endif
#    define GOODBYE_SONG        SONG(SONIC_RING)
#    if defined(DEFAULT_LAYER_SONGS)
#    undef DEFAULT_LAYER_SONGS
#    endif
#    define DEFAULT_LAYER_SONGS {SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND), SONG(OVERWATCH_THEME)}
#    if defined(CG_NORM_SONG)
#    undef CG_NORM_SONG
#    endif
#    define CG_NORM_SONG        SONG(MARIO_FIREBALL)
#    if defined(CG_SWAP_SONG)
#    undef CG_SWAP_SONG
#    endif
#    define CG_SWAP_SONG        SONG(MARIO_COIN)
#endif // USER_SONG_LIST

#endif

#if defined(POINTING_DEVICE_DRIVER_ANALOG_JOYSTICK)

// Joystick Hardware Configuration
#undef POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_RIGHT

// Joystick Movement Settings
#define ANALOG_JOYSTICK_AXIS_MIN 0          // Minimum range
#define ANALOG_JOYSTICK_AXIS_MAX 1000       // Maximum range
//#define ANALOG_JOYSTICK_AUTO_AXIS         // Uncomment to auto-set axis ranges

// Joystick Speed & Smoothing
#define ANALOG_JOYSTICK_SPEED_MAX 5          // Maximum speed
#define ANALOG_JOYSTICK_SPEED_REGULATOR 30   // Slows down movement (higher => slower)
#define ANALOG_JOYSTICK_READ_INTERVAL 5      // Milliseconds between reads

// Joystick Weights
#define ANALOG_JOYSTICK_WEIGHTS { \
    0,2,4,5,7,8,9,10,12,13,14,15,15,16,17,18,18,19,19,20,20,21,21, \
    21,22,22,22,22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23, \
    23,23,23,23,23,23,24,24,24,24,24,24,25,25,25,26,26,26,27,28, \
    28,29,29,30,31,32,33,34,35,36,37,38,40,41,43,44,46,48,49,51, \
    53,56,58,60,62,65,68,70,73,76,79,82,85,89,92,96,100 \
}

#endif

#if defined(MOUSEKEY_ENABLE)

// #define MOUSEKEY_MOVE_DELTA 8
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_MAX_SPEED 12
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0

#endif

#if defined(POINTING_DEVICE_DRIVER_CIRQUE_PINNACLE_I2C)

#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_ADDR 0x2A
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_3X
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_ROTATION_90_RIGHT

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 2

#endif