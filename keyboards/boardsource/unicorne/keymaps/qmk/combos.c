#include "combos.h"

// Define key combo arrays
const uint16_t PROGMEM combo_esc_q[] = {KC_ESC, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_q_w[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_w_e[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_e_r[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_r_t[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_y_t[] = {KC_Y, KC_T, COMBO_END};
const uint16_t PROGMEM combo_u_i[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_i_o[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_o_p[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_p_bsp[] = {KC_P, KC_BSPC, COMBO_END};

// Map combos to their resulting keycodes
combo_t combos[] = {
    [COMBO_1] = COMBO(combo_esc_q, KC_1),
    [COMBO_2] = COMBO(combo_q_w, KC_2),
    [COMBO_3] = COMBO(combo_w_e, KC_3),
    [COMBO_4] = COMBO(combo_e_r, KC_4),
    [COMBO_5] = COMBO(combo_r_t, KC_5),
    [COMBO_6] = COMBO(combo_y_t, KC_6),
    [COMBO_7] = COMBO(combo_u_i, KC_7),
    [COMBO_8] = COMBO(combo_i_o, KC_8),
    [COMBO_9] = COMBO(combo_o_p, KC_9),
    [COMBO_0] = COMBO(combo_p_bsp, KC_0)
};
uint16_t COMBO_LEN = COMBO_LENGTH;
