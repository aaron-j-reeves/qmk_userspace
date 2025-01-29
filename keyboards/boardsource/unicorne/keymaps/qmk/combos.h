// combos.h
#pragma once
#include QMK_KEYBOARD_H

#if defined(COMBO_ENABLE)

// Define combo indexes
enum combos {
    COMBO_1, // ESC + Q -> 1
    COMBO_2, // Q + W -> 2
    COMBO_3, // W + E -> 3
    COMBO_4, // E + R -> 4
    COMBO_5, // R + T -> 5
    COMBO_6, // Y + T -> 6
    COMBO_7, // U + I -> 7
    COMBO_8, // I + O -> 8
    COMBO_9, // O + P -> 9
    COMBO_0,  // P + Backspace -> 0
};

// Declare the combo map array
extern const combo_t combos[];

#endif