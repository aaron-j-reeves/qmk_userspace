// config.h
#pragma once

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200                       // limits maximum brightness of LEDs to 180 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_DEFAULT_ON true                              // Sets the default enabled state, if none has been set
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW            // Sets the default mode, if none has been set
#define RGB_MATRIX_DEFAULT_HUE 40                               // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 255                              // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS    // Sets the default brightness value, if none has been set
#define RGB_MATRIX_DEFAULT_SPD 100                              // Sets the default animation speed, if none has been set

#define TAPPING_TERM 250
#define COMBO_TERM 40
