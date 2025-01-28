#pragma once
#include "quantum.h"

// Define the total number of combos
//#define COMBO_COUNT 10

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
    COMBO_COUNT // number of combos
};

// Declare arrays for each combo
extern const uint16_t PROGMEM combo_esc_q[];
extern const uint16_t PROGMEM combo_q_w[];
extern const uint16_t PROGMEM combo_w_e[];
extern const uint16_t PROGMEM combo_e_r[];
extern const uint16_t PROGMEM combo_r_t[];
extern const uint16_t PROGMEM combo_y_t[];
extern const uint16_t PROGMEM combo_u_i[];
extern const uint16_t PROGMEM combo_i_o[];
extern const uint16_t PROGMEM combo_o_p[];
extern const uint16_t PROGMEM combo_p_bsp[];

// Declare the combo map array
extern combo_t key_combos[COMBO_COUNT];
