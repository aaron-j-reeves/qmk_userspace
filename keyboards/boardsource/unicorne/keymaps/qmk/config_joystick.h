// config_joystick.h
#pragma once

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
